#ifndef INCLUDE_THREADMANAGER_H_
#define INCLUDE_THREADMANAGER_H_

#include <atomic>
#include <ctime>

#include "include/View.h"
#include "include/Node.h"

class ThreadManager {
public:
        ThreadManager();
        explicit ThreadManager(View* v, Node* n);

        inline bool is_stopped() const { return stopped; }

    private:
        static void handler(int sig) {
            //ThreadManager::stopped = true;
        }

        float time_delta = 31;
        clock_t clk = clock(), tmp;

        View* view;
        Node* node;

        static void static_publish_ui(int sig) {
            instance -> publish_ui(sig);
        }

        void publish_ui(int sig);

        void on_ui_subscribe(TSN::user_information ui);
        void on_pm_subscribe(TSN::private_message pm);
        void on_rsp_subscribe(TSN::response rsp);
        void on_req_subscribe(TSN::request req);

        static bool stopped;

        static ThreadManager *instance;
};

#endif // INCLUDE_THREADMANAGER_H_
