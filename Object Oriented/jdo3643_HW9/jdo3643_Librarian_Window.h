#include<iostream>
#include<gtkmm.h>
#include<string>
using namespace std;

class Librarian_Window : public Gtk::Window
{
public:
	Librarian_Window();
	string get_name();
protected:
	void on_button_enter();
	Gtk::Box m_VBox;
	Gtk::Label Name_Label;
	Gtk::Entry Name_Entry; 
	Gtk::Button m_Button_Enter;
};
