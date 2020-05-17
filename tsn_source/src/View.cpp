#include "include/View.h"

#include <assert.h>

#include <cstring>
#include <ctime>
#include <mutex>
#include <regex>
#include <iostream>
#include <iomanip>
#include <initializer_list>

#include "include/FileWriter.h"

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

std::mutex buffer_mtx;
std::mutex screen_mtx;

View::View() {}

void View::init_curses() {
    initscr();              // Start Curses Mode
    cbreak();               // Get input as it is recieved
    noecho();               // Do not echo typed characters
    curs_set(0);            // Make mouse cursor invisible
    nodelay(stdscr, FALSE); // Make getch a blocking call in stdscr (why do anything until input?)

    int row, col;
    getmaxyx(stdscr, row, col); // Get the size of the screen.

    // Create the variables to calculate size of window elements.
    int main_win_h, main_win_w;
    int notif_win_h, notif_win_w, notif_off_y, notif_off_x;
    int prompt_win_h, prompt_win_w, prompt_off_y, prompt_off_x;

    // The main window box takes up a portion of the screen corresponding to
    // the two values given below.
    main_h = main_win_h = row * 7/9;
    main_w = main_win_w = col * 5/8;

    // Notification is as tall as the window, and resides to the right.
    notif_win_h = row;
    notif_w = notif_win_w = col - main_win_w;
    notif_off_y = 0;
    notif_off_x = main_win_w;

    // Prompt is just as wide as main window, and resides below it.
    prompt_h = prompt_win_h = row - main_win_h;
    prompt_w = prompt_win_w = main_win_w;
    prompt_off_y = main_win_h;
    prompt_off_x = 0;

    // Make the windows elements.
    main_win = newwin(main_win_h, main_win_w, 0, 0);
    notification_win = newwin(notif_win_h, notif_win_w, notif_off_y, notif_off_x);
    prompt_win = newwin(prompt_win_h, prompt_win_w, prompt_off_y, prompt_off_x);

    keypad(stdscr, TRUE);
    keypad(main_win, TRUE);
    keypad(notification_win, TRUE);
    keypad(prompt_win, TRUE);

    // Allows notification window to scroll when cursor prints to a new line
    scrollok(notification_win, TRUE);
    refresh_all();

    screen_mtx.lock();
    is_screen_init = true;
    screen_mtx.unlock();
}

std::string View::get_post_body() {
    curs_set(1);
    FIELD *fields[3];
    FORM *new_post_form;
    int ch, y, x;
    getmaxyx(main_win, y, x);

    fields[0] = new_field(1, 6, 0, 0, 0, 0);
    fields[1] = new_field(1, 28, 0, 10, 0, 0);
    fields[2] = NULL;

    set_field_buffer(fields[0], 0, "Post:");
    set_field_buffer(fields[1], 0, "");

    set_field_opts(fields[0], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
    set_field_opts(fields[1], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);

    set_field_back(fields[1], A_UNDERLINE);

    new_post_form = new_form(fields);
    set_form_win(new_post_form, main_win);
    set_form_sub(new_post_form, derwin(main_win, y - 10, x - 10, 2, 2));
    post_form(new_post_form);

    set_prompt({
            "Press [Enter] to create the post\n",
            "Hit [F1] to cancel"
            });

    form_driver(new_post_form, REQ_VALIDATION);

    refresh();
    wrefresh(main_win);

    std::string post_body;
    while ((ch = getch()) != KEY_F(1)) {
        switch (ch) {
            case KEY_DOWN:
                form_driver(new_post_form, REQ_NEXT_FIELD);
                form_driver(new_post_form, REQ_END_LINE);
                break;
            case KEY_UP:
                form_driver(new_post_form, REQ_PREV_FIELD);
                form_driver(new_post_form, REQ_END_LINE);
                break;
            case KEY_LEFT:
                form_driver(new_post_form, REQ_PREV_CHAR);
                break;
            case KEY_RIGHT:
                form_driver(new_post_form, REQ_NEXT_CHAR);
                break;
            case KEY_BACKSPACE:
                form_driver(new_post_form, REQ_PREV_CHAR);
                form_driver(new_post_form, REQ_DEL_CHAR);
                break;
            case 10:
                form_driver(new_post_form, REQ_VALIDATION);

                post_body = std::string(field_buffer(fields[1], 0));
                boost::trim(post_body);

                unpost_form(new_post_form);
                free_form(new_post_form);
                for (unsigned i = 0; i < 3; i++) {
                    free_field(fields[i]);
                }

                return post_body;
            default:
                form_driver(new_post_form, ch);
                break;
        }

        wrefresh(main_win);
    }

    unpost_form(new_post_form);
    free_form(new_post_form);
    for (unsigned i = 0; i < 3; i++) {
        free_field(fields[i]);
    }

    return "";

    /*std::string post_body;
      std::cout << Constants::HORIZONTAL_BAR << std::endl;
      std::cout << "Enter your post: ";
      std::getline(std::cin, post_body);
      std::cout << Constants::HORIZONTAL_BAR << std::endl;

      return post_body;*/
}

void View::end_curses() {
    screen_mtx.lock();
    is_screen_init = false;
    screen_mtx.unlock();

    curs_set(1);
    endwin();
    std::system("clear");
}

User View::show_signup_form() {
    FIELD *fields[9];
    FORM *signup_form;
    WINDOW *signup_window;
    int ch;

    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    int y, x;
    getmaxyx(stdscr, y, x);

    signup_window = newwin(y - 2, x - 2, 0, 0);

    fields[0] = new_field(1, 28, 0, 0, 0, 0);
    fields[1] = new_field(1, 40, 0, 30, 0, 0);
    fields[2] = new_field(1, 28, 2, 0, 0, 0);
    fields[3] = new_field(1, 40, 2, 30, 0, 0);
    fields[4] = new_field(1, 28, 4, 0, 0, 0);
    fields[5] = new_field(1, 40, 4, 30, 0, 0);
    fields[6] = new_field(1, 28, 6, 0, 0, 0);
    fields[7] = new_field(1, 40, 6, 30, 0, 0);
    fields[8] = NULL;

    set_field_buffer(fields[0], 0, "First Name:");
    set_field_buffer(fields[1], 0, "");
    set_field_buffer(fields[2], 0, "Last Name:");
    set_field_buffer(fields[3], 0, "");
    set_field_buffer(fields[4], 0, "Birth Date (mm/dd/yyyy):");
    set_field_buffer(fields[5], 0, "");
    set_field_buffer(fields[6], 0, "Interests (1,2,3):");
    set_field_buffer(fields[7], 0, "");

    set_field_opts(fields[0], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
    set_field_opts(fields[1], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);
    set_field_opts(fields[2], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
    set_field_opts(fields[3], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);
    set_field_opts(fields[4], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
    set_field_opts(fields[5], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);
    set_field_opts(fields[6], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
    set_field_opts(fields[7], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);

    set_field_back(fields[1], A_UNDERLINE);
    set_field_back(fields[3], A_UNDERLINE);
    set_field_back(fields[5], A_UNDERLINE);
    set_field_back(fields[7], A_UNDERLINE);

    signup_form = new_form(fields);
    set_form_win(signup_form, signup_window);
    set_form_sub(signup_form, derwin(signup_window, y - 10, x - 10, 2, 2));
    post_form(signup_form);

    mvwprintw(signup_window, y - 3, 2, "Use arrow keys to navigate and press ENTER to submit.");
    form_driver(signup_form, REQ_VALIDATION);

    refresh();
    wrefresh(signup_window);

    boost::uuids::uuid u = boost::uuids::random_generator()();
    std::string uuid = boost::lexical_cast<std::string>(u);

    std::string first_name;
    std::string last_name;
    std::string date_of_birth;

    std::string interests_line;
    std::vector<std::string> interests;

    User new_user;

    while ((ch = getch()) != -1) {
        switch (ch) {
            case KEY_DOWN:
                form_driver(signup_form, REQ_NEXT_FIELD);
                form_driver(signup_form, REQ_END_LINE);
                break;
            case KEY_UP:
                form_driver(signup_form, REQ_PREV_FIELD);
                form_driver(signup_form, REQ_END_LINE);
                break;
            case KEY_LEFT:
                form_driver(signup_form, REQ_PREV_CHAR);
                break;
            case KEY_RIGHT:
                form_driver(signup_form, REQ_NEXT_CHAR);
                break;
            case KEY_BACKSPACE:
                form_driver(signup_form, REQ_PREV_CHAR);
                form_driver(signup_form, REQ_DEL_CHAR);
                break;
            case 10:
                form_driver(signup_form, REQ_VALIDATION);

                first_name = std::string(field_buffer(fields[1], 0));
                last_name = std::string(field_buffer(fields[3], 0));
                date_of_birth = std::string(field_buffer(fields[5], 0));

                interests_line = std::string(field_buffer(fields[7], 0));


                boost::trim(first_name);
                boost::trim(last_name);
                boost::trim(date_of_birth);
                boost::trim(interests_line);

                boost::split(interests, interests_line, boost::is_any_of(","));

                // Signup complete, create and write the user to file.
                new_user = User(uuid, first_name, last_name, date_of_birth, interests);
                write_user_to_file(new_user);

                unpost_form(signup_form);
                free_form(signup_form);
                for (unsigned i = 0; i < 4; i++) {
                    free_field(fields[i]);
                }

                delwin(signup_window);
                endwin();
                return new_user;
            default:
                form_driver(signup_form, ch);
                break;
        }

        wrefresh(signup_window);
    }

    endwin();
    return User();
}

int View::show_main_menu(Node *node) {
    curs_set(0);
    set_prompt({
            "Use [Up] and [Down] to navigate\n",
            "Press [Enter] to select an option\n",
            "Hit [Q] to quit"
            });

    const char *choices[] = {
        " Posts",
        " Users",
        " Stats",
        "Request",
        "Re-sync",
        reinterpret_cast<char*>(NULL)
    };
    int n_choices = sizeof(choices)/sizeof(choices[0]);
    ITEM **items = reinterpret_cast<ITEM**>(calloc(n_choices, sizeof(ITEM*)));

    for (int i = 0; i < n_choices; ++i) {
        items[i] = new_item(choices[i], to_string(i).c_str());
    }

    main_menu = new_menu(reinterpret_cast<ITEM**>(items));

    // Create the subwindow for the mainwindow.
    int row, col;
    scale_menu(main_menu, &row, &col);
    main_sub_win = subwin(
            main_win,
            10,
            30,
            (main_h / 2) - (row / 2),
            (main_w / 2) - (col / 2) - 3);

    set_menu_win(main_menu, main_sub_win);
    set_menu_mark(main_menu, "");
    menu_opts_off(main_menu, O_SHOWDESC);

    // When using der/subwin, it is necessary to call
    // touchwin or touchline on main_win before calling
    // wrefresh on the sub_win. - From ncurses tutorial

    keypad(main_sub_win, TRUE);
    post_menu(main_menu);
    touchwin(main_win);
    wrefresh(main_sub_win);

    return get_menu_option(main_menu, main_sub_win, node);
}

int View::get_menu_option(MENU* menu, WINDOW* menu_win, Node *node) {
    int ch;
    while ((ch = getch())) {
        switch (ch) {
            case KEY_DOWN:
                menu_driver(menu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(menu, REQ_UP_ITEM);
                break;
            case 10:
                pos_menu_cursor(menu);
                wclear(menu_win);
                refresh();
                return item_index(current_item(menu));
            case 81:
            case 113:
                //raise(SIGINT);
                curs_set(1);
                end_curses();
                node -> dispose();
                exit(0);
                return -1;
        }
        wrefresh(menu_win);
    }
    return -1;
}


void View::show_splash() {
    initscr();
    curs_set(0);
    clear();
    refresh();
    int y, x;
    getmaxyx(stdscr, y, x);
    y = (y/2) - 5;
    x = (x/2) - 40;
    mvprintw(y++, x, "yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy");
    mvprintw(y++, x, "yyyyyyyyyyy/.-syyyyyyyyyyyyyyyyyyyyyysssyyyyyyyyyyyyyyyyyyyyyssyyyyyyyyyyys-./yy");
    mvprintw(y++, x, "yy:```````+. -yyyyyyyyyyyyyyyyyyyys/.   `/yyyyyyyyyyyyyyyyyy/  oyyyyyyyyyyo  +yy");
    mvprintw(y++, x, "yyoo/  /ooo  +yyyyyyyyyyyyyyyyyyys- `oso/syyyyyyyyyyyyyyyyyys+oyyyyyyyyyyy: `syy");
    mvprintw(y++, x, "yyyy:  syy/  :-.-+yyo/-.-:oyyyyyys`  -/oyyyo/-..-/sys+:-.-os--+ys/-.-/--os` -yyy");
    mvprintw(y++, x, "yyys` -yyy. `+o. .y/ `/o/ `syyyyyys/-`  .s/  :+/  -s. ./+:s+  o+` -+/.  oo  +yyy");
    mvprintw(y++, x, "yyyo  /yys  /ys` -o  .-----syyyyyssyys.  +  +yys. .- .syyyy- `s` -yyy/ .y: `syyy");
    mvprintw(y++, x, "yyy:  syy/  syo  +o  :o+--oyyyyy+``//:  /o  .+/- `o:  /++os` :s. `/+:  :s. -yyyy");
    mvprintw(y++, x, "yyy/:/yyy/-:yy+--syo:..-:oyyyyyys+-..-/oyyo:...-+sys/-..-so--oys:..-/--os--+yyyy");
    mvprintw(y++, x, "yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy");
    refresh();
    getch();
    end_curses();
}

void View::set_prompt(std::initializer_list<std::string> prompts) {
    assert(prompts.size() <= (unsigned) prompt_h);
    wclear(prompt_win);
    int line_count = 0;
    for (auto prompt : prompts) {
        mvwprintw(prompt_win, (prompt_h / 2) - (prompts.size() / 2) + line_count++,
                (prompt_w / 2) - (prompt.length() / 2), prompt.c_str());
    }
    refresh_all();
}


/*  AUTHOR: Kevin Tung
    list_all_users() is called from execute_main_menu(), and shows all users names.
    Kevin really hopes you do not need to read this to understand what the function does.
 */
void View::list_all_users(Node *node) {
    curs_set(0);
    set_prompt({
            "Use [Up] and [Down] to navigate\n",
            "Press [Enter] to select a user, or [M] to message them\n",
            "Hit [Q] to go back"
            });

    int n_choices = node -> get_users().size() + 1;
    ITEM **items = reinterpret_cast<ITEM**>(calloc(n_choices + 1, sizeof(ITEM*)));

    std::string first, last;
    for (int i = 0; i < n_choices; ++i) {
        first = node -> get_user_offset(i).get_first_name();
        last = node -> get_user_offset(i).get_last_name();
        items[i] = new_item(strdup(first.c_str()), strdup(last.c_str()));
    }

    items[n_choices] = NULL;

    main_menu = new_menu(reinterpret_cast<ITEM**>(items));

    // Create the subwindow for the mainwindow.
    int ch, col;
    scale_menu(main_menu, &ch, &col);
    main_sub_win = subwin(
            main_win,
            main_h - 4,
            col,
            2,
            2);

    WINDOW *info_win = subwin(
            main_win,
            main_h - 6,
            main_w - col - 8,
            2,
            col + 4);

    set_menu_win(main_menu, main_sub_win);
    set_menu_mark(main_menu, "");

    // When using der/subwin, it is necessary to call
    // touchwin or touchline on main_win before calling
    // wrefresh on the sub_win. - From ncurses tutorial

    keypad(main_sub_win, TRUE);
    post_menu(main_menu);
    touchwin(main_win);
    wrefresh(main_sub_win);

    std::string msg_body;
    User user;
    int flag = 1, flag2 = 1;
    std::string first_name, last_name, date_of_birth, interests_line;
    std::vector<std::string> interests;
    while ((ch = getch()) != -1 && flag) {
        switch (ch) {
            case KEY_DOWN:
                menu_driver(main_menu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(main_menu, REQ_UP_ITEM);
                break;
            case 10:
                pos_menu_cursor(main_menu);
                wclear(info_win);
                wrefresh(info_win);
                refresh();

                if (item_index(current_item(main_menu)) == 0) {
                    flag = 0;
                    curs_set(1);
                    FIELD *fields[9];
                    FORM *edit_form;

                    int y, x;
                    getmaxyx(info_win, y, x);

                    fields[0] = new_field(1, 12, 0, 0, 0, 0);
                    fields[1] = new_field(1, 40, 0, 14, 0, 0);
                    fields[2] = new_field(1, 12, 2, 0, 0, 0);
                    fields[3] = new_field(1, 40, 2, 14, 0, 0);
                    fields[4] = new_field(1, 12, 4, 0, 0, 0);
                    fields[5] = new_field(1, 40, 4, 14, 0, 0);
                    fields[6] = new_field(1, 12, 6, 0, 0, 0);
                    fields[7] = new_field(1, 40, 6, 14, 0, 0);
                    fields[8] = NULL;

                    set_field_buffer(fields[0], 0, "First Name:");
                    set_field_buffer(fields[1], 0, node -> get_node_user().get_first_name().c_str());
                    set_field_buffer(fields[2], 0, "Last Name:");
                    set_field_buffer(fields[3], 0, node -> get_node_user().get_last_name().c_str());
                    set_field_buffer(fields[4], 0, "Birth Date:");
                    set_field_buffer(fields[5], 0, node -> get_node_user().get_date_of_birth().c_str());
                    set_field_buffer(fields[6], 0, "Interests:");
                    set_field_buffer(fields[7], 0, boost::algorithm::join(node -> get_node_user().get_interests(), ",").c_str());

                    set_field_opts(fields[0], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
                    set_field_opts(fields[1], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);
                    set_field_opts(fields[2], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
                    set_field_opts(fields[3], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);
                    set_field_opts(fields[4], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
                    set_field_opts(fields[5], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);
                    set_field_opts(fields[6], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
                    set_field_opts(fields[7], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);

                    set_field_back(fields[1], A_UNDERLINE);
                    set_field_back(fields[3], A_UNDERLINE);
                    set_field_back(fields[5], A_UNDERLINE);
                    set_field_back(fields[7], A_UNDERLINE);

                    edit_form = new_form(fields);
                    set_form_win(edit_form, info_win);
                    set_form_sub(edit_form, derwin(info_win, y - 2, x - 2, 2, 2));
                    post_form(edit_form);

                    set_prompt({
                            "Use [Up] and [Down] to select fields\n",
                            "Press [Enter] to save changes\n",
                            "Hit [F1] to cancel"
                            });

                    form_driver(edit_form, REQ_VALIDATION);

                    refresh();
                    wrefresh(info_win);

                    while ((ch = getch()) != KEY_F(1)) {
                        switch (ch) {
                            case KEY_DOWN:
                                form_driver(edit_form, REQ_NEXT_FIELD);
                                form_driver(edit_form, REQ_END_LINE);
                                break;
                            case KEY_UP:
                                form_driver(edit_form, REQ_PREV_FIELD);
                                form_driver(edit_form, REQ_END_LINE);
                                break;
                            case KEY_LEFT:
                                form_driver(edit_form, REQ_PREV_CHAR);
                                break;
                            case KEY_RIGHT:
                                form_driver(edit_form, REQ_NEXT_CHAR);
                                break;
                            case KEY_BACKSPACE:
                                form_driver(edit_form, REQ_PREV_CHAR);
                                form_driver(edit_form, REQ_DEL_CHAR);
                                break;
                            case 10:
                                form_driver(edit_form, REQ_VALIDATION);

                                first_name = std::string(field_buffer(fields[1], 0));
                                last_name = std::string(field_buffer(fields[3], 0));
                                date_of_birth = std::string(field_buffer(fields[5], 0));
                                interests_line = std::string(field_buffer(fields[7], 0));

                                boost::trim(first_name);
                                boost::trim(last_name);
                                boost::trim(date_of_birth);
                                boost::trim(interests_line);

                                boost::split(interests, interests_line, boost::is_any_of(","));

                                user = User(node -> get_node_user());
                                user.set_first_name(first_name);
                                user.set_last_name(last_name);
                                user.set_date_of_birth(date_of_birth);
                                user.set_interests(interests);
                                write_user_to_file(user,
                                    node -> get_posts(node -> get_node_user()));
                                node -> set_node_user(user);

                                flag2 = 0;
                                break;
                            default:
                                form_driver(edit_form, ch);
                                break;
                        }

                        if (flag2 == 0) break;

                        wrefresh(main_win);
                    }

                    unpost_form(edit_form);
                    free_form(edit_form);
                    for (unsigned i = 0; i < 8; i++) {
                        free_field(fields[i]);
                    }
                } else {
                    user = node -> get_user_offset(item_index(current_item(main_menu)));
                    wprintw(info_win, std::string("Born on " + user.get_date_of_birth()).c_str());
                    wprintw(info_win, std::string("\n\nInterests\n=========\n").c_str());
                    for (unsigned i = 0; i < user.get_interests().size(); i++) {
                        wprintw(info_win, std::string(" - " + user.get_interests()[i] + "\n").c_str());
                    }

                    wprintw(info_win, std::string("\nPosts\n=====\n").c_str());
                    for (auto& x : node -> get_post_map()) {
                        if (x.first == user.get_uuid()) {
                            for (unsigned int i = 0; i < x.second.size(); i++) {
                                wprintw(info_win, std::string(" * " + x.second[i].get_body() + "\n").c_str());
                            }

                            break;
                        }
                    }
                }

                wrefresh(info_win);
                refresh();
                break;
            case 77:
            case 109:
                if (item_index(current_item(main_menu)) != 0) {
                    curs_set(1);
                    wclear(info_win);
                    wrefresh(info_win);
                    refresh();
                    flag = 0;
                    FIELD *fields[3];
                    FORM *msg_form;

                    int y, x;
                    getmaxyx(info_win, y, x);

                    fields[0] = new_field(1, 10, 0, 0, 0, 0);
                    fields[1] = new_field(1, 30, 0, 12, 0, 0);
                    fields[2] = NULL;

                    set_field_buffer(fields[0], 0, "Message:");
                    set_field_buffer(fields[1], 0, "");

                    set_field_opts(fields[0], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
                    set_field_opts(fields[1], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);

                    set_field_back(fields[1], A_UNDERLINE);

                    msg_form = new_form(fields);
                    set_form_win(msg_form, info_win);
                    set_form_sub(msg_form, derwin(info_win, y - 2, x - 2, 2, 2));
                    post_form(msg_form);

                    set_prompt({
                            "Press [Enter] to send the message\n",
                            "Hit [F1] to cancel"
                            });

                    form_driver(msg_form, REQ_VALIDATION);

                    refresh();
                    wrefresh(info_win);

                    while ((ch = getch()) != KEY_F(1)) {
                        switch (ch) {
                            case KEY_DOWN:
                                form_driver(msg_form, REQ_NEXT_FIELD);
                                form_driver(msg_form, REQ_END_LINE);
                                break;
                            case KEY_UP:
                                form_driver(msg_form, REQ_PREV_FIELD);
                                form_driver(msg_form, REQ_END_LINE);
                                break;
                            case KEY_LEFT:
                                form_driver(msg_form, REQ_PREV_CHAR);
                                break;
                            case KEY_RIGHT:
                                form_driver(msg_form, REQ_NEXT_CHAR);
                                break;
                            case KEY_BACKSPACE:
                                form_driver(msg_form, REQ_PREV_CHAR);
                                form_driver(msg_form, REQ_DEL_CHAR);
                                break;
                            case 10:
                                form_driver(msg_form, REQ_VALIDATION);

                                msg_body = std::string(field_buffer(fields[1], 0));
                                boost::trim(msg_body);

                                if (msg_body.empty()) {
                                    flag2 = 0;
                                } else {
                                    node -> publish(PrivateMessage(user.get_uuid(),
                                                node -> get_node_user().get_uuid(), msg_body).to_TSN_pm());
                                    flag2 = 0;
                                }

                                break;
                            default:
                                form_driver(msg_form, ch);
                                break;
                        }

                        if (flag2 == 0) break;

                        wrefresh(main_win);
                    }

                    unpost_form(msg_form);
                    free_form(msg_form);
                    for (unsigned i = 0; i < 3; i++) {
                        free_field(fields[i]);
                    }
                }

                break;
            case 81:
            case 113:
                flag = 0;
                break;
        }

        if (flag == 0) break;

        wrefresh(main_sub_win);
    }

    wclear(main_sub_win);
    wclear(info_win);
    wrefresh(main_sub_win);
    wrefresh(info_win);
    delwin(main_sub_win);
    delwin(info_win);
    wrefresh(main_win);
    refresh();
}

void View::display_threads(Node *node) {
    curs_set(0);
    set_prompt({
            "Use [Up] and [Down] to navigate\n",
            "Press [N] to create a new post, or [Enter] to reply\n",
            "Hit [Q] to go back"});

    std::vector<std::string> tabs = std::vector<std::string>();
    std::vector<Post> all_posts = node -> get_all_posts(node -> get_parent_posts(), &tabs, "");

    int n_choices = all_posts.size();
    ITEM **items = reinterpret_cast<ITEM**>(calloc(n_choices + 1, sizeof(ITEM*)));

    for (int i = 0; i < n_choices; ++i) {
        int offset = node -> get_user_from_uuid(all_posts[i].get_uuid());
        items[i] = new_item(
                strdup(std::string(tabs[i] + "(" + node -> get_user_offset(offset).get_first_name() + " " + node -> get_user_offset(offset).get_last_name() + ")").c_str()),
                strdup(all_posts[i].get_body().c_str()));
    }

    items[n_choices] = NULL;

    main_menu = new_menu(reinterpret_cast<ITEM**>(items));

    // Create the subwindow for the mainwindow.
    main_sub_win = subwin(
            main_win,
            main_h - 4,
            main_w - 4,
            2,
            2);

    set_menu_win(main_menu, main_sub_win);
    set_menu_mark(main_menu, "");

    // When using der/subwin, it is necessary to call
    // touchwin or touchline on main_win before calling
    // wrefresh on the sub_win. - From ncurses tutorial

    keypad(main_sub_win, TRUE);
    post_menu(main_menu);
    touchwin(main_win);
    wrefresh(main_sub_win);

    int y, x, selected_index;
    int ch = 0, flag = 1;
    FIELD *fields[3];
    FORM *new_post_form;
    std::string post_body;
    while (ch != 81 && ch != 113) {
        switch (ch) {
            case KEY_DOWN:
                menu_driver(main_menu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(main_menu, REQ_UP_ITEM);
                break;
            case 78:
            case 110:
                wclear(main_win);
                wrefresh(main_win);
                refresh();

                curs_set(1);
                getmaxyx(main_win, y, x);

                fields[0] = new_field(1, 6, 0, 0, 0, 0);
                fields[1] = new_field(1, 28, 0, 10, 0, 0);
                fields[2] = NULL;

                set_field_buffer(fields[0], 0, "Post:");
                set_field_buffer(fields[1], 0, "");

                set_field_opts(fields[0], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
                set_field_opts(fields[1], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);

                set_field_back(fields[1], A_UNDERLINE);

                new_post_form = new_form(fields);
                set_form_win(new_post_form, main_win);
                set_form_sub(new_post_form, derwin(main_win, y - 10, x - 10, 2, 2));
                post_form(new_post_form);

                set_prompt({
                        "Press [Enter] to create the post\n",
                        "Hit [F1] to cancel"
                        });

                form_driver(new_post_form, REQ_VALIDATION);

                refresh();
                wrefresh(main_win);

                while ((ch = getch()) != KEY_F(1)) {
                    switch (ch) {
                        case KEY_DOWN:
                            form_driver(new_post_form, REQ_NEXT_FIELD);
                            form_driver(new_post_form, REQ_END_LINE);
                            break;
                        case KEY_UP:
                            form_driver(new_post_form, REQ_PREV_FIELD);
                            form_driver(new_post_form, REQ_END_LINE);
                            break;
                        case KEY_LEFT:
                            form_driver(new_post_form, REQ_PREV_CHAR);
                            break;
                        case KEY_RIGHT:
                            form_driver(new_post_form, REQ_NEXT_CHAR);
                            break;
                        case KEY_BACKSPACE:
                            form_driver(new_post_form, REQ_PREV_CHAR);
                            form_driver(new_post_form, REQ_DEL_CHAR);
                            break;
                        case 10:
                            form_driver(new_post_form, REQ_VALIDATION);

                            post_body = std::string(field_buffer(fields[1], 0));
                            boost::trim(post_body);

                            if (!post_body.empty()) {
                                Post new_post(node -> get_node_user().get_number_of_highest_post(), post_body);
                                new_post.set_uuid(node -> get_node_user().get_uuid());
                                node -> add_post(&node -> get_node_user(), new_post);
                                write_post_to_file(new_post);
                            }

                            flag = 0;
                            break;
                        default:
                            form_driver(new_post_form, ch);
                            break;
                    }

                    if (flag == 0) break;

                    wrefresh(main_win);
                }

                unpost_form(new_post_form);
                free_form(new_post_form);
                for (unsigned i = 0; i < 3; i++) {
                    free_field(fields[i]);
                }

                flag = 0;
                break;
            case 10:
                selected_index = item_index(current_item(main_menu));
                wclear(main_win);
                wrefresh(main_win);
                refresh();

                curs_set(1);
                getmaxyx(main_win, y, x);

                fields[0] = new_field(1, 6, 0, 0, 0, 0);
                fields[1] = new_field(1, 28, 0, 10, 0, 0);
                fields[2] = NULL;

                set_field_buffer(fields[0], 0, "Post:");
                set_field_buffer(fields[1], 0, "");

                set_field_opts(fields[0], O_VISIBLE | O_PUBLIC | O_AUTOSKIP);
                set_field_opts(fields[1], O_VISIBLE | O_PUBLIC | O_EDIT | O_ACTIVE);

                set_field_back(fields[1], A_UNDERLINE);

                new_post_form = new_form(fields);
                set_form_win(new_post_form, main_win);
                set_form_sub(new_post_form, derwin(main_win, y - 10, x - 10, 2, 2));
                post_form(new_post_form);

                set_prompt({
                        "Press [Enter] to create the post\n",
                        "Hit [F1] to cancel"
                        });

                form_driver(new_post_form, REQ_VALIDATION);

                refresh();
                wrefresh(main_win);

                while ((ch = getch()) != KEY_F(1)) {
                    switch (ch) {
                        case KEY_DOWN:
                            form_driver(new_post_form, REQ_NEXT_FIELD);
                            form_driver(new_post_form, REQ_END_LINE);
                            break;
                        case KEY_UP:
                            form_driver(new_post_form, REQ_PREV_FIELD);
                            form_driver(new_post_form, REQ_END_LINE);
                            break;
                        case KEY_LEFT:
                            form_driver(new_post_form, REQ_PREV_CHAR);
                            break;
                        case KEY_RIGHT:
                            form_driver(new_post_form, REQ_NEXT_CHAR);
                            break;
                        case KEY_BACKSPACE:
                            form_driver(new_post_form, REQ_PREV_CHAR);
                            form_driver(new_post_form, REQ_DEL_CHAR);
                            break;
                        case 10:
                            form_driver(new_post_form, REQ_VALIDATION);

                            post_body = std::string(field_buffer(fields[1], 0));
                            boost::trim(post_body);

                            if (!post_body.empty()) {
                                Post new_post(node -> get_node_user().get_number_of_highest_post(), post_body);
                                new_post.set_uuid(node -> get_node_user().get_uuid());

                                new_post.get_parent_post().owner_uuid = all_posts[selected_index].get_uuid();
                                new_post.get_parent_post().post_id = all_posts[selected_index].get_serial_number();

                                /*Post::PostData new_data = Post::PostData();
                                new_data.owner_uuid = node -> get_node_user().get_uuid();
                                new_data.post_id = new_post.get_serial_number();
                                node -> get_post(all_posts[selected_index].get_uuid(), all_posts[selected_index].get_serial_number()).get_child_posts().push_back(new_data);*/

                                node -> add_post(&node -> get_node_user(), new_post);
                                write_post_to_file(new_post);
                            }

                            flag = 0;
                            break;
                        default:
                            form_driver(new_post_form, ch);
                            break;
                    }

                    if (flag == 0) break;

                    wrefresh(main_win);
                }

                unpost_form(new_post_form);
                free_form(new_post_form);
                for (unsigned i = 0; i < 3; i++) {
                    free_field(fields[i]);
                }

                flag = 0;
                break;
        }

        if (flag == 0) break;

        wrefresh(main_sub_win);
        ch = getch();
    }

    wclear(main_sub_win);
    wrefresh(main_sub_win);
    delwin(main_sub_win);
    wrefresh(main_win);
    refresh();
}

std::string View::str_truncate(std::string input_string, size_t len) {
    assert(len > 0);
    if (input_string.length() > len) {
        input_string.resize(len);
    }
    return input_string;
}

void View::refresh_all() {
    box(main_win, 0, 0);
    box(notification_win, 0, 0);
    box(prompt_win, 0, 0);
    wrefresh(main_win);
    wrefresh(notification_win);
    wrefresh(prompt_win);
    refresh();
}

void View::show_node_statistics(Node *node) {
    if (node -> get_users().size() == 0) {
        notify("[TSN] There are 0 other nodes on the network.\n");
        return;
    }

    std::string output;

    // One is subtracted since we do not want to count ourself.
    unsigned int other_known_nodes = node -> get_users().size() - 1;
    output = output + "There are " + std::to_string(other_known_nodes) + " other nodes on the network.\n";

    // Count the total content on the network.
    unsigned int total_content_count = 0;
    for (auto it = node -> get_users().cbegin(); it != node -> get_users().cend(); ++it) {
        total_content_count += it -> get_number_of_highest_post();
    }

    // Count the known content in this node.
    unsigned int known_content_count = 0;
    for (auto it = node -> get_post_map().cbegin(); it != node -> get_post_map().cend(); ++it) {
        std::vector<Post> known_post_vector = it -> second;
        known_content_count += known_post_vector.size();
    }

    // Known percentage is expressed in terms from 0 to 1.
    float known_percentage;
    if (total_content_count == 0) {
        known_percentage = 1.00;
    } else {
        known_percentage = static_cast<float>(known_content_count) / total_content_count;
    }

    output = output + "Of these nodes, you have " + std::to_string(known_percentage * 100)
        + " percent of the posts available.\n";

    notify("[TSN] " + output);
}

int View::get_number_from_user(unsigned int max_number, std::string prompt) {
    end_curses();
    bool input_is_valid = false;
    std::string input_line = "";
    std::regex number_regex("[[:digit:]]+");    // Regex matches any number of digits.
    unsigned int selection = max_number + 1;

    while (!input_is_valid) {
        std::cout << prompt;
        std::getline(std::cin, input_line);
        if (std::regex_match(input_line, number_regex)) {
            try {
                selection = std::stoi(input_line);
            } catch (std::exception& e) {
                std::cerr << "ERROR: Exception thrown in get_number_from_user(): "
                    << e.what() << std::endl;
            }

            if (0 <= selection && selection <= max_number) {
                input_is_valid = true;
            }
        }
    }
    init_curses();
    return selection;
}

void View::notify(std::string notif) {
    for (unsigned int i = notif_w - 3; i < notif.size(); i += notif_w) {
        notif.insert(i, "   ");
    }

    wprintw(notification_win, "| %s\n", notif.c_str());
    wborder(notification_win, '|', ' ', ' ', ' ', '|', ' ', '|', ' ');
    wrefresh(notification_win);
    refresh();
}

void View::clear_buffer() {
    buffer_mtx.lock();
    if (!buffer.empty()) {
        std::istringstream iss(buffer);
        for (std::string line; std::getline(iss, line);) {
            notify(line);
        }

        buffer = "";
    }

    buffer_mtx.unlock();
}

void View::_buffer_print(std::string output) {
    stringstream ss;
    ss << output << std::endl;

    screen_mtx.lock();
    if (!is_screen_init) {
        buffer_mtx.lock();
        buffer += ss.str();
        buffer_mtx.unlock();
    } else {
        clear_buffer();
        notify(ss.str());
    }

    screen_mtx.unlock();
}

std::string View::get_time() const {
    std::time_t t = std::time(nullptr);
    stringstream ss;
    ss << std::put_time(std::localtime(&t), "[%H:%m] ");
    return ss.str();
}

void View::print_user_online(User user) {
    std::string msg = " has come online!\n";
    msg = get_time() + user.get_first_name() + msg;
    _buffer_print(msg);
}

void View::print_post(Post post) {
    std::string post_msg = "POST: ";
    post_msg = get_time() + post_msg + post.get_body() + "\n";
    _buffer_print(post_msg);
}

void View::print_pm(PrivateMessage pm, Node *node) {
    std::string msg = get_time() + "[";
    for (auto user : node -> get_users()) {
        if (user.get_uuid() == pm.get_sender_uuid()) {
            msg += user.get_first_name();
            break;
        }
    }

    msg += "] " + pm.get_message_body() + "\n";
    _buffer_print(msg);
}
