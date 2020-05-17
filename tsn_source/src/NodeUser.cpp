#include "include/NodeUser.h"

// Instance intailly set to NULL, will be initalized one time only on call
NodeUser* NodeUser::instance = 0;  

// Empty constructor
NodeUser::NodeUser() {} 

// Initalize instance the first time only
NodeUser* NodeUser::get_instance()
{
    if(!instance)
    {
        instance = new NodeUser();
    }
    assert(instance != 0);
    return instance;
}

// Getter of selected_interest
std::string NodeUser::get_selected_interest()
{
    return selected_interest;
}

// Setter of selected_interest
void NodeUser::set_selected_interest(std::string si)
{
    selected_interest = si;
}
