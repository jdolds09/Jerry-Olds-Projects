#ifndef INCLUDE_VIEW_H_
#define INCLUDE_VIEW_H_

#include <ncurses.h>
#include <form.h>
#include <menu.h>

#include <initializer_list>
#include <iostream>
#include <string>

#include "include/Node.h"
#include "include/Post.h"
#include "include/PrivateMessage.h"

class View {
    public:
        View();

        void init_curses();
        void end_curses();

        int get_menu_option(MENU* menu, WINDOW* menu_win, Node *node);
        void show_splash();
        void set_prompt(std::initializer_list<std::string> prompts);

        User show_signup_form();

        int show_main_menu(Node *node);

        std::string get_post_body();

        void list_all_users(Node *node);
        std::string str_truncate(std::string input_string, size_t len);
        void refresh_all();
        void show_node_statistics(Node *node);

        int get_number_from_user(unsigned int max_number, std::string prompt);

        void display_threads(Node *node);
        void display_threads(Node *node, Post post);

        void notify(std::string notif);
        void clear_buffer();
        void print_user_online(User user);
        void print_post(Post post);
        void print_pm(PrivateMessage pm, Node *node);
        void _buffer_print(std::string output);

    private:
        WINDOW* main_win;
        WINDOW* notification_win = NULL;
        WINDOW* prompt_win;
        WINDOW* main_sub_win;

        MENU* main_menu;

        int main_h;
        int main_w;

        int prompt_h;
        int prompt_w;

        int notif_w;

        std::string buffer;

        std::string get_time() const;

        bool is_screen_init = false;
};

#endif // INCLUDE_VIEW_H_
