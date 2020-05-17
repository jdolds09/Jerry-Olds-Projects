#include "include/Controller.h"

#include <assert.h>

#include <csignal>
#include <fstream>
#include <iterator>

#include "include/FileWriter.h"
#include "include/PrivateMessage.h"

#include "lib/json11/json11.hpp"

#include <boost/algorithm/string.hpp>

Controller::Controller(View* v, Node* n) : view(v), node(n), thread_m(v, n) {
    // Create the input file stream to load user data from "~/.tsn"
    // If the file does not exist, then start user creation.
    std::ifstream user_file(std::getenv("HOME") + Constants::DATA_FILE);
    if (!user_file) {
        User new_user = view -> show_signup_form();
        node -> set_node_user(new_user);
    } else {
        read_user_from_file(user_file);
    }
}

void Controller::cli() {
    view -> show_splash();
    view -> init_curses();

    while (!thread_m.is_stopped()) {
        int selection = view -> show_main_menu(node);
        if (selection == 3) view -> end_curses();
        execute_main_menu(selection);
        if (selection == 3) view -> init_curses();
    }

    node -> dispose();
    view -> end_curses();
}

void Controller::test(int selection) {
    execute_main_menu(selection);
    node -> dispose();
}

/*  AUTHOR: Kevin Tung
    execute_main_menu() will call show_main_menu() and recieve an integer selection from it.
    Upon recieving the selection, a switch statement will execute based on the selection. The amount of cases
    should match the variable max_option in show_main_menu().
*/

//      Posts   -> Create Post, Request Post, Display Thread
//     Profile  -> Select Interest, Edit User Information
//      Users   -> Show a User, Private Message
//    Node Info -> Resync, Settings

// PM ->
// Send message to who?
// View user ->
// View who?
void Controller::execute_main_menu(int selection) {
    switch (selection) {
        case -1: break;
        case 0:     // Create a post
            create_post();
            break;
        case 1:     // List all(?) users
            view -> list_all_users(node);
            break;
        case 2:
            view -> show_node_statistics(node);
            break;
        case 3:
            request_posts();
            break;
        case 4:     // Resets user data and data structures
            curs_set(1);
            resync_data();
            break;
        default:
            std::cerr << "ERROR: show_main_menu() returned value " << selection
                << ", but there was not a case for it." << std::endl;
            break;
    }
}

void Controller::create_post() {
    std::string post_body = view -> get_post_body();
    if (!post_body.empty()) {
        Post new_post(node -> get_node_user().get_number_of_highest_post(), post_body);
        new_post.set_uuid(node -> get_node_user().get_uuid());
        node -> add_post(&node -> get_node_user(), new_post);
        write_user_to_file(node -> get_node_user(),
            node -> get_posts(node -> get_node_user()));
    }
}

void Controller::request_posts() {
    time_t current_time = get_current_time();
    bool wants_posts = true;
    int non_exit_flag = 0;

    std::vector<std::vector<unsigned long>> rq_vector(node -> get_users().size());

    /*struct node_request
    {
        char fulfiller_uuid[UUID_SIZE];  // the owner of the posts
        sequence<serial_number> requested_posts;
    };*/

    if (time_of_last_post_request + Constants::POST_REQUEST_TIMEOUT < current_time) {
        int choice = 0;
        while (wants_posts) {
            // We list all users to request posts from.
            // While the user wants more posts, if they enter 0 they do not want any more posts.
            view -> list_all_users(node);
            choice = node -> get_users().size();
            choice = view -> get_number_from_user(choice - 1,
                "Enter the number of to the user you want to request from (0 to cancel): ");
            if (choice == 0) {
                wants_posts = false;
            } else {
                non_exit_flag = 1;
                /*bool found = false;                 // We check to see if the node_request exists for the specified user.
                for (auto node : desired_posts)
                {
                    if (strcmp(node -> fulfiller_uuid, users[choice].uuid) == 0)
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)                         // If we cannot find the node_request, we create it and add it to the desired_posts.
                {
                    TSN::node_request new_node_request;
                    new_node_request.requested_posts.length(100);
                    strcpy(new_node_request.fulfiller_uuid, users[choice].uuid);
                    req.user_requests[desired_posts.size()] = new_node_request;
                    desired_posts.push_back(new_node_request);
                }*/

                // Now we examine the request user's highest number post.
                // We can choose any number up to the highest post.
                // 0 may serve as a senteniel since post serial numbers start at one.
                int number_of_desired_post = 0;
                number_of_desired_post = view -> get_number_from_user(
                    node -> get_users()[choice].get_number_of_highest_post(),
                    "Enter the number of the post you want to add to your request: ");

                if (number_of_desired_post != 0) {
                    rq_vector[choice].push_back(number_of_desired_post);
                } else {
                    non_exit_flag = 0;
                }
                /*if (number_of_desired_post != 0)
                {
                    for (unsigned int i = 0; i < desired_posts.size(); i++)
                    {
                        auto node = desired_posts[i];
                        if (strcmp(node -> fulfiller_uuid, users[choice].uuid) == 0)
                        {
                            node -> requested_posts[request_counts[i]++] = number_of_desired_post;
                            node -> requested_posts.length(request_counts[i]);
                            break;
                        }
                    }
                }*/
                // In the event that the user entered 0, they did not want any
                // of the posts specific to the user. They still could ask for
                // other posts, so we do not change wants_posts.
            }
        }

        std::vector<std::string> uuids;
        if (non_exit_flag) {
            for (unsigned i = 0; i < rq_vector.size(); i++) {
                if (rq_vector[i].size() != 0) {
                    uuids.push_back(std::string(node -> get_users()[i].get_uuid()));
                }
            }

            for (auto it = rq_vector.begin(); it != rq_vector.end();) {
                if (it -> size() == 0) {
                    it = rq_vector.erase(it);
                } else {
                    ++it;
                }
            }

            TSN::request req;
            strncpy(req.uuid, node -> get_users()[0].to_TSN_ui().uuid, sizeof(req.uuid));
            req.user_requests.length(rq_vector.size());
            for (unsigned i = 0; i < rq_vector.size(); i++) {
                strncpy(req.user_requests[i].fulfiller_uuid, uuids[i].c_str(),
                    sizeof(req.user_requests[i].fulfiller_uuid));

                req.user_requests[i].requested_posts.length(rq_vector[i].size());
                for (unsigned j = 0; j < rq_vector[i].size(); j++) {
                    req.user_requests[i].requested_posts[j] = rq_vector[i][j];
                }
            }

            view -> notify("Sending out the request...");
            time_of_last_post_request = current_time;
            node -> publish(req);
        }
    } else {
        std::string wait_notification = "Slow down! You are not allowed to make a request for posts for another ";
        wait_notification += (Constants::POST_REQUEST_TIMEOUT - (current_time - time_of_last_post_request));
        wait_notification += " seconds.";
        view -> notify(wait_notification);
    }

    // if someone wants to request posts
    // they need to be able to see all the people they can request from
    // then they select one person to request from
    // then they need to choose posts from that user
    // then they can keep choosing more people's posts
    // then they can send the request
    // there is a lock of requests every minute
    // to build all the requests, we can build up
}

/*  AUTHOR: Kevin Tung
    resync_data() is called from execute_main_menu().
    Currrently it only calls create_new_user(), which resets the user data file.
    This will later wipe data structures.
*/
void Controller::resync_data() {
    endwin();

    node -> get_post_map().clear();
    node -> get_users().clear();

    User new_user = view -> show_signup_form();
    node -> set_node_user(new_user);
}

time_t Controller::get_current_time() {
    return std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

void Controller::read_user_from_file(std::ifstream& ifs) {
    // We reached here meaning the user already has an account
    std::string line;
    std::getline(ifs, line);
    unsigned int found = line.find_first_not_of(" \t");
    if (found != std::string::npos && line[found] == '{') {
        std::string contents(std::istreambuf_iterator<char>{ifs}, {});
        std::string err;

        json11::Json json = json11::Json::parse(contents, err);

        json11::Json user_json = json["node_user"];
        std::string uuid = user_json["uuid"].string_value();
        std::string first_name = user_json["first_name"].string_value();
        std::string last_name = user_json["last_name"].string_value();
        std::string date_of_birth = user_json["date_of_birth"].string_value();

        std::vector<std::string> interests;
        for (auto i : user_json["interests"].array_items()) {
            interests.push_back(i.string_value());
        }

        std::vector<Post> posts;
        for (auto pj : json["posts"].array_items()) {
            std::string p_uuid = pj["uuid"].string_value();
            unsigned long serial_number = pj["serial_number"].number_value();
            std::string body = pj["body"].string_value();
            time_t date_of_creation = pj["date_of_creation"].number_value();

            Post post(serial_number, body);
            post.set_date_of_creation(date_of_creation);
            post.set_uuid(p_uuid);

            Post::PostData parent_data = Post::PostData();
            parent_data.owner_uuid = pj["parent_post"]["owner_uuid"].string_value();
            parent_data.post_id = pj["parent_post"]["post_id"].number_value();
            post.set_parent_post(parent_data);

            for (auto cp : pj["child_posts"].array_items()) {
                Post::PostData child_data = Post::PostData();
                child_data.owner_uuid = cp["owner_uuid"].string_value();
                child_data.post_id = cp["post_id"].number_value();
                post.add_child_post(child_data);
            }

            posts.push_back(post);
        }

        unsigned long long number_of_highest_post = posts.size();

        User user(uuid, first_name, last_name, date_of_birth, interests, number_of_highest_post);
        node -> set_node_user(user);
    } else {
        // Initialize his or her data by reading line-by-line
        std::string uuid;
        std::string first_name;
        std::string last_name;
        std::string date_of_birth;
        std::vector<std::string> interests;
        unsigned long long number_of_highest_post = 0;

        std::getline(ifs, uuid);
        std::getline(ifs, first_name);
        std::getline(ifs, last_name);
        std::getline(ifs, date_of_birth);

        // Split interest line w/ delimiter to read it into a vector.
        std::string interest_line;
        if (interest_line != "~") {
            std::getline(ifs, interest_line);
            boost::split(interests, interest_line, boost::is_any_of(Constants::DELIMITER));
        }

        User user(uuid, first_name, last_name, date_of_birth, interests, number_of_highest_post);
        node -> set_node_user(user);

        std::string post_line;
        while (std::getline(ifs, post_line)) {
            if (post_line == "") continue;
            Post post;
            std::stringstream tmp;
            tmp << post_line;
            tmp >> post;
            post.set_uuid(uuid);
            node -> add_post(&node -> get_node_user(), post);
        }
    }



    ifs.close();
}
