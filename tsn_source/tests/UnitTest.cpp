#define BOOST_TEST_MODULE UnitTest

#include "include/Controller.h"
#include "include/FileWriter.h"
#include "include/Node.h"
#include "include/Post.h"
#include "include/PrivateMessage.h"
#include "include/User.h"
#include "include/TypeConverter.h"

#include "standalone/TSN.h"

#include <boost/test/included/unit_test.hpp>

#include <stdio.h>
#include <string>
#include <vector>

BOOST_AUTO_TEST_SUITE (UnitTest)

BOOST_AUTO_TEST_CASE(PostTest) {
    unsigned int serial = 142;
    TSN::response D;
    std::string uuid = "d21633d5-12fb-4c93-a4a4-a56f06b7ba24";
    strncpy (D.uuid, uuid.c_str(), sizeof(D.uuid));
    D.uuid[sizeof(D.uuid)-1] = '\0';
    D.post_id = serial;
    D.post_body = DDS::string_dup("Hello Test"); 
    D.date_of_creation = 1000;

    Post post(D);

    BOOST_CHECK(uuid == post.get_uuid());
    BOOST_CHECK(serial == post.get_serial_number());
    BOOST_CHECK("Hello Test" == post.get_body());
    BOOST_CHECK(1000 == post.get_date_of_creation());
}

BOOST_AUTO_TEST_CASE(NodeTest) {
    TSN::user_information D;
    std::string uuid = "d21633d5-12fb-4c93-a4a4-a56f06b7ba24";
    D.first_name = DDS::string_dup("Testy");
    D.last_name = DDS::string_dup("McTestFace");
    D.date_of_birth = 1;
    D.interests.length(1);
    D.interests[0] = DDS::string_dup("Testing");
    D.number_of_highest_post = 0;
    strncpy (D.uuid, uuid.c_str(), sizeof(D.uuid));
    D.uuid[sizeof(D.uuid)-1] = '\0';

    User user(D);
    
    Node node;
    BOOST_CHECK(!node.user_exists(uuid));
    node.add_user(user);
    BOOST_CHECK(node.user_exists(uuid));

    node.set_selected_interest("Testing TSN");
    BOOST_CHECK("Testing TSN" == node.get_selected_interest());
}

BOOST_AUTO_TEST_CASE(PrivateMessageTest) {
    TSN::private_message D;
    std::string receiver_uuid = "d21633d5-12fb-4c93-a4a4-a56f06b7ba24";
    std::string sender_uuid = "a12643675-245b-v4ka-58dj-oijg3p984948";
    D.message_body = DDS::string_dup("Secret Hello");
    D.date_of_creation = 1000;    
    strncpy (D.receiver_uuid, receiver_uuid.c_str(), sizeof(D.receiver_uuid));
    strncpy (D.sender_uuid, sender_uuid.c_str(), sizeof(D.sender_uuid));

    PrivateMessage private_message(D);
    
    BOOST_CHECK(receiver_uuid == private_message.get_receiver_uuid());
    BOOST_CHECK(sender_uuid == private_message.get_sender_uuid());
    BOOST_CHECK(1000 == private_message.get_date_of_creation());
    BOOST_CHECK("Secret Hello" == private_message.get_message_body());
}

BOOST_AUTO_TEST_CASE(UserTest) {
    TSN::user_information D;
    std::string uuid = "d21633d5-12fb-4c93-a4a4-a56f06b7ba24";
    D.first_name = DDS::string_dup("Testy");
    D.last_name = DDS::string_dup("McTestFace");
    D.date_of_birth = 1;
    D.interests.length(1);
    D.interests[0] = DDS::string_dup("Testing");
    D.number_of_highest_post = 0;
    strncpy (D.uuid, uuid.c_str(), sizeof(D.uuid));
    D.uuid[sizeof(D.uuid)-1] = '\0';

    User user(D);

    BOOST_CHECK(uuid == user.get_uuid());
    BOOST_CHECK("Testy" == user.get_first_name());
    BOOST_CHECK("McTestFace" == user.get_last_name());
    BOOST_CHECK(time_to_str(static_cast<time_t>(1)) == user.get_date_of_birth());
    std::vector<std::string> interests;
    interests = user.get_interests();
    for (auto i : interests) {
        BOOST_CHECK(i == "Testing");
    }
    BOOST_CHECK(0 == user.get_number_of_highest_post());

    user = User();
    user.set_first_name("Testy");
    user.set_last_name("McTestFace");
    user.set_date_of_birth("1");
    user.set_interests(interests);

    BOOST_CHECK("Testy" == user.get_first_name());
    BOOST_CHECK("McTestFace" == user.get_last_name());
    BOOST_CHECK("1" == user.get_date_of_birth());
    interests = user.get_interests();
    for (auto i : interests) {
        BOOST_CHECK(i == "Testing");
    }

}

BOOST_AUTO_TEST_CASE(ControllerTest) {
    time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    time_t controller_time = Controller::get_current_time();
    float error = time/controller_time;
    BOOST_CHECK(error > 0.99);
}

BOOST_AUTO_TEST_SUITE_END( )

