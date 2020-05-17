#include "include/ThreadManager.h"

#include <csignal>

#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

bool ThreadManager::stopped = false;
ThreadManager *ThreadManager::instance = 0;

ThreadManager::ThreadManager() {}

ThreadManager::ThreadManager(View* v, Node* n) : view(v), node(n) {
    ThreadManager::instance = this;

    struct sigaction sigact;
    memset(&sigact, 0, sizeof(sigact));
    sigact.sa_handler = ThreadManager::handler;
    sigaction(SIGINT, &sigact, 0);

    // Initialize helpers
    node -> init();

    // Bind OSPL events
    node -> ui_helper.listener -> signal_data_ready.connect(
        bind(&ThreadManager::on_ui_subscribe, this, _1));
    node -> msg_helper.listener -> signal_data_ready.connect(
        bind(&ThreadManager::on_pm_subscribe, this, _1));
    node -> rsp_helper.listener -> signal_data_ready.connect(
        bind(&ThreadManager::on_rsp_subscribe, this, _1));
    node -> req_helper.listener -> signal_data_ready.connect(
        bind(&ThreadManager::on_req_subscribe, this, _1));

    signal(SIGALRM, static_publish_ui);
    alarm(1);
}

void ThreadManager::publish_ui(int sig) {
    if (!is_stopped()) {
        node -> publish(node -> get_node_user().to_TSN_ui());
        alarm(30);
    }
}

void ThreadManager::on_ui_subscribe(TSN::user_information ui) {
    User user(ui);

    // Ignore ourselves
    if (user.get_uuid() == node -> get_node_user().get_uuid()) {
        return;
    }

    if (!node -> user_exists(user.get_uuid())) {
        if (!user.get_uuid().empty()) {
            node -> add_user(user);
            view -> print_user_online(user);
        }
    } else {
        for (unsigned int i = 0; i < node -> get_users().size(); i++) {
            if (strcmp(node -> get_users()[i].to_TSN_ui().uuid, ui.uuid) == 0) {
                node -> get_users()[i] = user;
                return;
            }
        }
    }
}

void ThreadManager::on_pm_subscribe(TSN::private_message pm) {
    // Check that message is aimed at us
    if (std::string(pm.receiver_uuid) == node -> get_node_user().get_uuid()) {
        PrivateMessage p_msg(pm);
        view -> print_pm(p_msg, node);
    }
}

void ThreadManager::on_rsp_subscribe(TSN::response rsp) {
    std::string rsp_uuid = uuid_to_str(rsp.uuid);
    if (node -> user_exists(rsp_uuid)) {
        long id(rsp.post_id);
        Post new_post(rsp);
        new_post.set_date_of_creation(rsp.date_of_creation);

        std::vector<Post> tmp_posts = node -> get_posts(rsp_uuid);
        if ((unsigned) (id - 1) >= tmp_posts.size()) {
            tmp_posts.resize(id);
        }

        tmp_posts[id - 1] = new_post;
        view -> print_post(new_post);
    }
}

void ThreadManager::on_req_subscribe(TSN::request req) {
    // Ignore requests we send out
    if (strcmp(req.uuid, node -> get_node_user().to_TSN_ui().uuid) == 0) {
        return;
    }

    auto node_reqs = req.user_requests;
    for (DDS::ULong i = 0; i < node_reqs.length(); i++) {
        auto nr = node_reqs[i];

        // Is the request directed at us?
        if (strcmp(nr.fulfiller_uuid, node -> get_node_user().to_TSN_ui().uuid) == 0) {
            auto serial_numbers = nr.requested_posts;
            for (DDS::ULong j = 0; j < serial_numbers.length(); j++) {
                // Make sure serial number is within bounds
                auto sn = serial_numbers[j];
                if (sn > 0 && sn <= node -> get_node_user().get_number_of_highest_post()) {
                    unsigned idx = sn - 1;

                    // Send a response for each post requested
                    TSN::response new_rsp;
                    strncpy(new_rsp.uuid,
                        node -> get_node_user().to_TSN_ui().uuid,
                        sizeof(new_rsp.uuid));

                    std::vector<Post> usr_posts = node -> get_posts(
                        node -> get_node_user().get_uuid());

                    if (idx < usr_posts.size()) {
                        new_rsp.post_id = sn;
                        new_rsp.post_body = DDS::string_dup((usr_posts)[idx]
                                .get_body().c_str());
                        new_rsp.date_of_creation = (usr_posts)[idx].get_date_of_creation();
                        node -> publish(new_rsp);
                        usleep(100000);
                    }
                }
            }
        }
    }
}
