#ifndef INCLUDE_USER_H_
#define INCLUDE_USER_H_

#include <string>
#include <vector>

#include "include/TypeConverter.h"

#include "lib/json11/json11.hpp"

class User {
    public:
        User();

        User(std::string u, std::string fn, std::string ln, std::string dob,
            std::vector<std::string> in, unsigned long long high = 0) : uuid(u), first_name(fn),
            last_name(ln), date_of_birth(dob), interests(in), number_of_highest_post(high) {}

        // C-tor to convert a TSN::user_information to a User class.
        explicit User(TSN::user_information TSN_ui);

        // Overloaded operator assignment
        User& operator=(const User& other);

        // Getters
        TSN::user_information to_TSN_ui() const;

        std::string get_uuid() const;
        std::string get_first_name() const;
        std::string get_last_name() const;
        std::string get_date_of_birth() const;
        const std::vector<std::string>& get_interests() const;
        unsigned long long get_number_of_highest_post() const;

        // Setters
        // NOTE: We don't ever want to change UUID.
        // Name, DOB, interests, and highest post can all
        // change because of editing, but UUID should be inmutable.

        // ++n_of_highest_post equivalent. Normal users don't need this;
        // Encapsulate via derived NodeUser class?
        unsigned long long increment_number_of_highest_post();

        void set_first_name(std::string fname);
        void set_last_name(std::string lname);
        void set_date_of_birth(std::string dob);
        void set_interests(std::vector<std::string> inter);

        json11::Json to_json() const {
            return json11::Json::object {
                {"uuid", uuid},
                {"first_name", first_name},
                {"last_name", last_name},
                {"date_of_birth", date_of_birth},
                {"interests", interests}
            };
        }

    private:
        std::string uuid;
        std::string first_name;
        std::string last_name;
        std::string date_of_birth;
        std::vector<std::string> interests;
        unsigned long long number_of_highest_post;
};

#endif // INCLUDE_USER_H_
