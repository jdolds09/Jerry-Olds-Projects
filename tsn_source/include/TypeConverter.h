#ifndef INCLUDE_TYPECONVERTER_H_
#define INCLUDE_TYPECONVERTER_H_

#include <ctime>
#include <string>

#include "standalone/ccpp_TSN.h"

std::string uuid_to_str(TSN::user_information::_uuid uuid);
time_t str_to_time(std::string time_str);
std::string time_to_str(time_t time);

#endif // INCLUDE_TYPECONVERTER_H_
