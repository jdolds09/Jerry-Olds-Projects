#ifndef INCLUDE_NODE_H_
#define INCLUDE_NODE_H_

#include <map>
#include <string>
#include <vector>

#include "include/DDSHelper.h"
#include "include/Post.h"
#include "include/User.h"

class Node {
    public:
        Node();

        bool user_exists(std::string uuid);
        bool user_exists(User user);

        // Getters
        User& get_node_user();
        User& get_user_offset(unsigned int index);
        std::string get_selected_interest();

        void init();

        std::map<std::string, std::vector<Post>>& get_post_map();          // Get all posts
        std::vector<Post> get_posts(User user);                        // Get all posts by User
        std::vector<Post> get_posts(std::string uuid);                 // Get all posts by User's UUID

        std::vector<Post> get_parent_posts();                          // Get all top level posts (with no parents).
        std::vector<Post> get_child_posts(Post post);
        std::vector<Post> get_all_posts(std::vector<Post> psts, std::vector<std::string> *tabs, std::string indent);

        Post get_post(User user, unsigned long serial_number);          // Get a specific post by User and serial number
        Post get_post(std::string uuid, unsigned long serial_number);   // Get a specific post by User UUID and serial

        std::vector<User>& get_users();

        Post get_post_from_data(Post::PostData data);

        int get_user_from_uuid(std::string uuid);

        // Setters
        void set_node_user(const User& user);
        void set_selected_interest(std::string interest);

        void add_user(User user);

        void add_post(User *user, Post post);

        // Helper functions for DDS
        void publish(TSN::user_information ui);
        void publish(TSN::request rq);
        void publish(TSN::response rsp);
        void publish(TSN::private_message pm);

        std::vector<TSN::user_information> receive_ui();
        std::vector<TSN::request> receive_rq();
        std::vector<TSN::response> receive_rsp();
        std::vector<TSN::private_message> receive_msg();

        /* Begin helper class definitions */
        DDSHelper<
            TSN::user_information,
            TSN::user_informationSeq,
            TSN::user_informationTypeSupport_var,
            TSN::user_informationTypeSupport,
            TSN::user_informationDataWriter_var,
            TSN::user_informationDataWriter,
            TSN::user_informationDataReader_var,
            TSN::user_informationDataReader
        > ui_helper;

        DDSHelper<
            TSN::request,
            TSN::requestSeq,
            TSN::requestTypeSupport_var,
            TSN::requestTypeSupport,
            TSN::requestDataWriter_var,
            TSN::requestDataWriter,
            TSN::requestDataReader_var,
            TSN::requestDataReader
        > req_helper;

        DDSHelper<
            TSN::response,
            TSN::responseSeq,
            TSN::responseTypeSupport_var,
            TSN::responseTypeSupport,
            TSN::responseDataWriter_var,
            TSN::responseDataWriter,
            TSN::responseDataReader_var,
            TSN::responseDataReader
        > rsp_helper;

        DDSHelper<
            TSN::private_message,
            TSN::private_messageSeq,
            TSN::private_messageTypeSupport_var,
            TSN::private_messageTypeSupport,
            TSN::private_messageDataWriter_var,
            TSN::private_messageDataWriter,
            TSN::private_messageDataReader_var,
            TSN::private_messageDataReader
        > msg_helper;
        /* End helper class definitions */

        void dispose();

    private:
        User node_user;
        std::string selected_interest;

        std::map<std::string, std::vector<Post>> posts;
        std::vector<User> users;
};

#endif // INCLUDE_NODE_H_
