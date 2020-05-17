#include "include/Node.h"

#include <assert.h>

#include "include/DDSHelper.h"

// Explicit empty constructor
Node::Node() {}

void Node::init() {
    ui_helper = DDSHelper<
            TSN::user_information,
            TSN::user_informationSeq,
            TSN::user_informationTypeSupport_var,
            TSN::user_informationTypeSupport,
            TSN::user_informationDataWriter_var,
            TSN::user_informationDataWriter,
            TSN::user_informationDataReader_var,
            TSN::user_informationDataReader
        >(const_cast<char*>("user_information"), true, true);

    req_helper = DDSHelper<
            TSN::request,
            TSN::requestSeq,
            TSN::requestTypeSupport_var,
            TSN::requestTypeSupport,
            TSN::requestDataWriter_var,
            TSN::requestDataWriter,
            TSN::requestDataReader_var,
            TSN::requestDataReader
        >(const_cast<char*>("request"), true, true);

    rsp_helper = DDSHelper<
            TSN::response,
            TSN::responseSeq,
            TSN::responseTypeSupport_var,
            TSN::responseTypeSupport,
            TSN::responseDataWriter_var,
            TSN::responseDataWriter,
            TSN::responseDataReader_var,
            TSN::responseDataReader
        >(const_cast<char*>("response"), true, true);

    msg_helper = DDSHelper<
            TSN::private_message,
            TSN::private_messageSeq,
            TSN::private_messageTypeSupport_var,
            TSN::private_messageTypeSupport,
            TSN::private_messageDataWriter_var,
            TSN::private_messageDataWriter,
            TSN::private_messageDataReader_var,
            TSN::private_messageDataReader
        >(const_cast<char*>("private_message"), true, true);
}

bool Node::user_exists(std::string uuid) {
    for (User i : users) {
        if (i.get_uuid() == uuid) return true;
    }

    return false;
}

bool Node::user_exists(User user) {
    return user_exists(user.get_uuid());
}

// Getters
User& Node::get_node_user() {
    return node_user;
}

// get_user_offset is used to retrieve a User from the array of users stored in the node.
User& Node::get_user_offset(unsigned int index) {
    assert(0 <= index && index <= get_users().size());
    if (index == 0) {
        return get_node_user();
    } else {
        return get_users()[index - 1];
    }
}

std::string Node::get_selected_interest() {
    return selected_interest;
}

std::map<std::string, std::vector<Post>>& Node::get_post_map() {
    return posts;
}

std::vector<Post> Node::get_posts(User user) {
    return get_posts(user.get_uuid());
}

std::vector<Post> Node::get_posts(std::string uuid) {
    assert(user_exists(uuid));
    return posts.find(uuid) -> second;
}

std::vector<Post> Node::get_parent_posts() {
    std::vector<Post> parent_vector;
    std::vector<Post> temp_posts;
    auto post_map = get_post_map();
    for (auto it = post_map.begin(); it != post_map.end(); ++it) {
        temp_posts = it->second;
        for (auto v_it = temp_posts.begin(); v_it != temp_posts.end(); ++v_it) {
            if (v_it->get_parent_post().owner_uuid == "") {
                parent_vector.push_back(*v_it);
            }
        }
    }

    return parent_vector;
}

std::vector<Post> Node::get_child_posts(Post post) {
    std::vector<Post> child_vector;
    for (Post::PostData data : post.get_child_posts()) {
        child_vector.push_back(get_post_from_data(data));
    }

    return child_vector;
}

std::vector<Post> Node::get_all_posts(std::vector<Post> psts, std::vector<std::string> *tabs, std::string indent) {
    std::vector<Post> all;
    for (unsigned int i = 0; i < psts.size(); i++) {
        all.push_back(psts[i]);
        tabs -> push_back(indent);

        std::vector<Post> children = get_all_posts(get_child_posts(psts[i]), tabs, indent + "\t");
        all.insert(all.end(), children.begin(), children.end());
    }

    return all;
    /*
void View::show_thread(Post post, int indent_num, Node *node) {
    std::string indent_string = "";
    for (int i = 0; i < indent_num; i++) {
        indent_string += "\t";
    }

    std::cout << indent_string << post.get_body() << std::endl;
    std::vector<Post> children = node -> get_child_posts(post);
    unsigned int num_children = children.size();
    for (unsigned int i = 0; i < num_children; i++) {
        show_thread(children[i], indent_num + 1, node);
    }
}
*/
}

int Node::get_user_from_uuid(std::string uuid) {
    if (node_user.get_uuid() == uuid) return 0;
    for (unsigned int i = 0; i < users.size(); i++) {
        if (users[i].get_uuid() == uuid) return i + 1;
    }

    return -1;
}

Post Node::get_post(User user, unsigned long serial_number) {
    return get_post(user.get_uuid(), serial_number);
}

Post Node::get_post(std::string uuid, unsigned long serial_number) {
    std::vector<Post> temp = get_posts(uuid);
    unsigned int temp_end = temp.size();
    for (unsigned int i = 0; i < temp_end; i++) {
        if (temp[i].get_serial_number() == serial_number) {
            return temp[i];
        }
    }

    Post dummy;
    return dummy;
}

Post Node::get_post_from_data(Post::PostData data) {
    return get_post(data.owner_uuid, data.post_id);
}

std::vector<User>& Node::get_users() {
    return users;
}

// Setters
void Node::set_node_user(const User& user) {
    node_user = user;
    add_user(user);
}

void Node::set_selected_interest(std::string interest) {
    selected_interest = interest;
}

void Node::add_user(User user) {
    if (!user_exists(user)) {   // Check to ensure we are not creating a duplicate user.
        users.push_back(user);
        posts.insert(
            std::make_pair(
                user.get_uuid(),
                std::vector<Post>()));
    }
}

void Node::add_post(User *user, Post post) {
    posts.find(user -> get_uuid()) -> second.push_back(post);
    user -> increment_number_of_highest_post();
}

void Node::publish(TSN::user_information ui) {
    ui_helper.publish(ui);
}

void Node::publish(TSN::request rq) {
    req_helper.publish(rq);
}

void Node::publish(TSN::response rsp) {
    rsp_helper.publish(rsp);
}

void Node::publish(TSN::private_message pm) {
    msg_helper.publish(pm);
}

std::vector<TSN::user_information> Node::receive_ui() {
    return ui_helper.receive();
}

std::vector<TSN::request> Node::receive_rq() {
    return req_helper.receive();
}

std::vector<TSN::response> Node::receive_rsp() {
    return rsp_helper.receive();
}

std::vector<TSN::private_message> Node::receive_msg() {
    return msg_helper.receive();
}

void Node::dispose() {
    // Dispose of our OpenSplice objects when done
    ui_helper.dispose();
    rsp_helper.dispose();
    req_helper.dispose();
    msg_helper.dispose();
}
