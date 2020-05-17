#include "include/User.h"

// Explicit empty constructor
User::User() {}

// C-tor to convert a TSN::user_information to a User class.
User::User(TSN::user_information TSN_ui) {
    uuid = std::string(TSN_ui.uuid);
    first_name = std::string(TSN_ui.first_name);
    last_name = std::string(TSN_ui.last_name);
    date_of_birth = time_to_str(static_cast<time_t>(TSN_ui.date_of_birth));

    auto interest_sequence = TSN_ui.interests;
    std::vector<std::string> interest_vector;
    unsigned int sequence_length = interest_sequence.length();
    for (unsigned int i = 0; i < sequence_length; i++) {
        interest_vector.push_back(std::string(interest_sequence[i]));
    }

    interests = interest_vector;
    number_of_highest_post = TSN_ui.number_of_highest_post;
}

User& User::operator=(const User& other) {
    // Prevent self assignment
    if (this != &other) {
        uuid = other.get_uuid();
        first_name = other.get_first_name();
        last_name = other.get_last_name();
        date_of_birth = other.get_date_of_birth();
        interests = other.get_interests();
        number_of_highest_post = other.get_number_of_highest_post();
    }

    return *this;
}

TSN::user_information User::to_TSN_ui() const {
    TSN::user_information TSN_ui;

    strncpy(TSN_ui.uuid, uuid.c_str(), sizeof(TSN_ui.uuid));
    TSN_ui.first_name = DDS::string_dup(first_name.c_str());
    TSN_ui.last_name = DDS::string_dup(last_name.c_str());
    TSN_ui.date_of_birth = str_to_time(date_of_birth);

    unsigned int num_interests = interests.size();
    TSN_ui.interests.length(num_interests);
    for (unsigned int i = 0; i < num_interests; i++) {
        TSN_ui.interests[i] = DDS::string_dup(interests[i].c_str());
    }

    TSN_ui.number_of_highest_post = number_of_highest_post;
    return TSN_ui;
}

std::string User::get_uuid() const {
    return uuid;
}

std::string User::get_first_name() const {
    return first_name;
}

std::string User::get_last_name() const {
    return last_name;
}

std::string User::get_date_of_birth() const {
    return date_of_birth;
}

const std::vector<std::string>& User::get_interests() const {
    return interests;
}

unsigned long long User::get_number_of_highest_post() const {
    return number_of_highest_post;
}

// Setters
unsigned long long User::increment_number_of_highest_post() {
    return ++number_of_highest_post;
}

void User::set_first_name(std::string fname) {
    first_name = fname;
}

void User::set_last_name(std::string lname) {
    last_name = lname;
}

void User::set_date_of_birth(std::string dob) {
    date_of_birth = dob;
}

void User::set_interests(std::vector<std::string> inter) {
    interests.swap(inter);
}
