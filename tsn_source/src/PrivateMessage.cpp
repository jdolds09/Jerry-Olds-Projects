#include "include/PrivateMessage.h"

PrivateMessage::PrivateMessage(std::string r_uuid, std::string s_uuid, std::string msg_body)
    : receiver_uuid(r_uuid), sender_uuid(s_uuid), message_body(msg_body) {
    date_of_creation = std::chrono::system_clock::to_time_t(
        std::chrono::system_clock::now());
}

PrivateMessage::PrivateMessage(TSN::private_message TSN_pm) {
    message_body = std::string(TSN_pm.message_body);
    date_of_creation = static_cast<time_t>(TSN_pm.date_of_creation);
    receiver_uuid = std::string(TSN_pm.receiver_uuid);
    sender_uuid = std::string(TSN_pm.sender_uuid);
}

TSN::private_message PrivateMessage::to_TSN_pm() const {
    TSN::private_message pm;

    strncpy(pm.receiver_uuid, receiver_uuid.c_str(), sizeof(pm.receiver_uuid));
    strncpy(pm.sender_uuid, sender_uuid.c_str(), sizeof(pm.sender_uuid));
    pm.message_body = DDS::string_dup(message_body.c_str());
    pm.date_of_creation = date_of_creation;

    return pm;
}

std::string PrivateMessage::get_receiver_uuid() const {
    return receiver_uuid;
}

std::string PrivateMessage::get_sender_uuid() const {
    return sender_uuid;
}

time_t PrivateMessage::get_date_of_creation() const {
    return date_of_creation;
}
void PrivateMessage::set_date_of_creation(long d) {
    date_of_creation = d;
}

std::string PrivateMessage::get_message_body() const {
    return message_body;
}
