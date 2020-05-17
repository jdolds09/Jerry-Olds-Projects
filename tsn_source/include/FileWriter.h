#ifndef INCLUDE_FILEWRITER_H_
#define INCLUDE_FILEWRITER_H_

#include <string>
#include <vector>

#include "include/Post.h"
#include "include/User.h"

struct Constants {
    static const std::string DELIMITER;
    static const std::string DATA_FILE;
    static const std::string HORIZONTAL_BAR;
    static const unsigned int POST_REQUEST_TIMEOUT;
};

void write_user_to_file(
    User node_user,
    std::vector<Post> posts = std::vector<Post>()
);

void write_post_to_file(Post new_post);

#endif // INCLUDE_FILEWRITER_H_
