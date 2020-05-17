#ifndef INCLUDE_PRIVATEMESSAGE_H_
#define INCLUDE_PRIVATEMESSAGE_H_

#include <ctime>
#include <chrono>
#include <istream>
#include <string>
#include <vector>

#include "standalone/ccpp_TSN.h"
#include "include/User.h"

class PrivateMessage {
    public:
       PrivateMessage(std::string r_uuid, std::string s_uuid, std::string msg_body);
       explicit PrivateMessage(TSN::private_message TSN_pm);

       TSN::private_message to_TSN_pm() const;

       std::string get_receiver_uuid() const;
       std::string get_sender_uuid() const;
       std::string get_message_body() const;
       time_t get_date_of_creation() const;
       void set_date_of_creation(long d);

    private:
        std::string receiver_uuid;
        std::string sender_uuid;
        std::string message_body;
        time_t date_of_creation;
};

#endif // INCLUDE_PRIVATEMESSAGE_H_
