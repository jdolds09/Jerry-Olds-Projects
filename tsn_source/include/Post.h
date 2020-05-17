#ifndef INCLUDE_POST_H_
#define INCLUDE_POST_H_

#include <chrono>
#include <istream>
#include <string>
#include <vector>

#include "standalone/ccpp_TSN.h"

#include "lib/json11/json11.hpp"

class Post {
    public:
        class PostData {
            public:
                std::string owner_uuid = "";
                unsigned long post_id = 0;

                // Overloaded operator assignment
                PostData& operator=(const PostData& other) {
                    // Prevent self assignment
                    if (this != &other) {
                        owner_uuid = other.owner_uuid;
                        post_id = other.post_id;
                    }

                    return *this;
                }

                json11::Json to_json() const {
                    return json11::Json::object {
                        {"owner_uuid", owner_uuid},
                        {"post_id", static_cast<double>(post_id)}
                    };
                }
        };

        explicit Post(unsigned long s = 0,
            std::string b = "THIS POST IS NOT AVAILABLE, AND HAS BEEN ADDED TO YOUR NEXT REQUEST.");
        explicit Post(TSN::response TSN_resp);

        // Getters
        std::string get_uuid() const;
        unsigned long get_serial_number() const;
        std::string get_body() const;
        time_t get_date_of_creation() const;

        void set_uuid(std::string u);

        PostData& get_parent_post();
        void set_parent_post(PostData data);

        std::vector<PostData>& get_child_posts();
        void add_child_post(PostData child);

        void set_date_of_creation(long d);

        friend std::istream& operator>>(std::istream& is, Post& post);

        json11::Json to_json() const {
            return json11::Json::object {
                {"uuid", uuid},
                {"serial_number", static_cast<double>(serial_number)},
                {"body", body},
                {"date_of_creation", static_cast<double>(date_of_creation)},
                {"parent_post", parent_post},
                {"child_posts", child_posts}
            };
        }

    private:
        std::string uuid;
        unsigned long serial_number;
        std::string body;
        time_t date_of_creation;

        PostData parent_post;

        std::vector<PostData> child_posts;
};

#endif // INCLUDE_POST_H_
