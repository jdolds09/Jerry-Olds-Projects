#include "include/FileWriter.h"

#include <fstream>

// We'll use pipe to delimit
const std::string Constants::DELIMITER = "|";

// Our file for storing user info and posts
const std::string Constants::DATA_FILE = "/.tsn";

const std::string Constants::HORIZONTAL_BAR = "----------------------------";

// Amount of time between post requests that we must make
const unsigned int Constants::POST_REQUEST_TIMEOUT = 60;

/*
 * Writes the given user information to the .tsn file by overwriting
 */
void write_user_to_file(User node_user, std::vector<Post> posts) {
    std::string home(std::getenv("HOME"));
    std::ofstream ofs(home + Constants::DATA_FILE);
    if (ofs) {
        json11::Json json = json11::Json::object {
            {"node_user", node_user},
            {"posts", posts}
        };

        ofs << json.dump();
    }

    ofs.close();

    /*if (ofs) {
        ofs << uuid << std::endl;
        ofs << f_name << std::endl;
        ofs << l_name << std::endl;
        ofs << date << std::endl;

        if (interests.size() == 0) {
            ofs << "~" << std::endl;
        } else {
            for (unsigned i = 0; i < interests.size(); i++) {
                ofs << interests[i];
                if (i == interests.size() - 1) {
                    ofs << std::endl;
                } else {
                    ofs << Constants::DELIMITER;
                }
            }
        }

        for (Post post : posts) {
            // ofs << post.get_serial_number() << Constants::DELIMITER;
            //ofs << post.get_date_of_creation() << Constants::DELIMITER;
            //ofs << post.get_body() << std::endl;

            ofs << post.get_serial_number() << Constants::DELIMITER;
            ofs << post.get_date_of_creation() << Constants::DELIMITER;
            ofs << post.get_body() << Constants::DELIMITER;
            ofs << post.get_parent_post().owner_uuid << Constants::DELIMITER;
            ofs << post.get_parent_post().post_id;

            auto children = post.get_child_posts();
            for (unsigned i = 0; i < children.size(); i++) {
                ofs << Constants::DELIMITER << children[i].owner_uuid
                    << Constants::DELIMITER;
                ofs << children[i].post_id;
            }

            ofs << std::endl;
        }
    }

    ofs.close();*/
}

/*
 * Appends post data as a string to the .tsn file
 */
void write_post_to_file(Post new_post) {
    std::string home = getenv("HOME");
    std::ofstream ofs(home + Constants::DATA_FILE, std::ios_base::app);

    if (ofs) {
        
    }

    /*if (ofs) {
        ofs << new_post.get_serial_number() << Constants::DELIMITER;
        ofs << new_post.get_date_of_creation() << Constants::DELIMITER;
        ofs << new_post.get_body() << Constants::DELIMITER;
        ofs << new_post.get_parent_post().owner_uuid << Constants::DELIMITER;
        ofs << new_post.get_parent_post().post_id;
        auto children = new_post.get_child_posts();
        for (unsigned i = 0; i < children.size(); i++) {
            ofs << Constants::DELIMITER << children[i].owner_uuid
                << Constants::DELIMITER;
            ofs << children[i].post_id;
        }

        ofs << std::endl;
    }

    ofs.close();*/
}
