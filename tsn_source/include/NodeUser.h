#ifndef NODEUSER_H
#define NODEUSER_H

#include "include/User.h"

class NodeUser
{
	public:
        static NodeUser* get_instance();
		std::string get_selected_interest();
        void set_selected_interest(std::string si);

    private:
        NodeUser();
        static NodeUser* instance;
		std::string selected_interest;
};

#endif
