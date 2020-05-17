#include<iostream>
#include<gtkmm.h>
#include<string>
using namespace std;

class Customer_Window : public Gtk::Window
{
public:
	Customer_Window();
	vector<string> get_entries();
protected:
	void on_button_enter();
	Gtk::Box m_VBox;
	Gtk::Label Name_Label;
	Gtk::Entry Name_Entry;
	Gtk::Label Phone_Label;
	Gtk::Entry Phone_Entry;
	Gtk::Label Email_Label;
	Gtk::Entry Email_Entry;
	Gtk::Button m_Button_Enter; 
};
