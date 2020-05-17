#include "include/Post.h"

Post::Post(unsigned long s, std::string b) : serial_number(s), body(b) {
    uuid = "POST-NOT-OWNED";
    date_of_creation = std::chrono::system_clock::to_time_t(
        std::chrono::system_clock::now());

    parent_post.owner_uuid = "";
    parent_post.post_id = 0;
}

Post::Post(TSN::response TSN_resp) {
    uuid = std::string(TSN_resp.uuid);
    serial_number = TSN_resp.post_id;
    body = std::string(TSN_resp.post_body);
    date_of_creation = static_cast<time_t>(TSN_resp.date_of_creation);

    parent_post.owner_uuid = std::string(TSN_resp.parent_post.owner_uuid);
    parent_post.post_id = static_cast<unsigned long>(TSN_resp.parent_post.post_id);

    auto child_post_sequence = TSN_resp.child_posts;
    unsigned int sequence_length = child_post_sequence.length();
    for (unsigned int i = 0; i < sequence_length; i++) {
        PostData data = PostData();
        data.owner_uuid = std::string(child_post_sequence[i].owner_uuid);
        data.post_id = static_cast<unsigned long>(child_post_sequence[i].post_id);
        child_posts.push_back(data);
    }
}

std::string Post::get_uuid() const {
    return uuid;
}

void Post::set_uuid(std::string u) {
    uuid = u;
}

unsigned long Post::get_serial_number() const {
    return serial_number;
}

std::string Post::get_body() const {
    return body;
}

time_t Post::get_date_of_creation() const {
    return date_of_creation;
}

Post::PostData& Post::get_parent_post() {
    return parent_post;
}

void Post::set_parent_post(PostData data) {
    parent_post = data;
}

std::vector<Post::PostData>& Post::get_child_posts() {
    return child_posts;
}

void Post::add_child_post(PostData child) {
    child_posts.push_back(child);
}

void Post::set_date_of_creation(long d) {
    date_of_creation = d;
}

std::istream& operator>>(std::istream& is, Post& post) {
    char delim;

    is >> post.serial_number;
    is >> delim;
    is >> post.date_of_creation;
    is >> delim;
    std::getline(is, post.body);

    return is;
}
