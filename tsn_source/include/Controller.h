#ifndef INCLUDE_CONTROLLER_H_
#define INCLUDE_CONTROLLER_H_

#include <atomic>

#include "include/ThreadManager.h"
#include "include/View.h"

class Controller {
    public:
        Controller(View* v, Node* n);

        void cli();
        void test(int selection);

        void execute_main_menu(int selection);
        void request_posts();
        void resync_data();
        void create_post();

        static time_t get_current_time();

        void read_user_from_file(std::ifstream& ifs);

    private:
        View* view;
        Node* node;
        ThreadManager thread_m;

        // Time variable since last post request
        // So that we cannot send them rapidly
        time_t time_of_last_post_request = 0;
};

#endif // INCLUDE_CONTROLLER_H_
