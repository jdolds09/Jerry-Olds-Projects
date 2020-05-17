#include "include/TypeConverter.h"

#include <iomanip>
#include <sstream>

#include <boost/lexical_cast.hpp>

std::string uuid_to_str(TSN::user_information::_uuid uuid) {
    return boost::lexical_cast<std::string>(uuid);
}

time_t str_to_time(std::string time_str) {
    struct std::tm tm;
    memset(&tm, 0, sizeof tm);

    std::istringstream iss(time_str);
    iss >> std::get_time(&tm, "%m/%d/%Y");
    return mktime(&tm);
}

std::string time_to_str(time_t time) {
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&time), "%m/%d/%Y");
    return oss.str();
}
