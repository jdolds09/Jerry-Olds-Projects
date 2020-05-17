#include<iostream>
#include<gtkmm.h>
#include<string>
using namespace std;

class Payment_Window : public Gtk::Window
{
public:
	Payment_Window();
	~Payment_Window();
	string get_entry();
protected:
	void on_button_enter();
	Gtk::Box m_VBox;
	Gtk::Label Payment_Label;
	Gtk::Entry Payment_Entry;
	Gtk::Button m_Button_Enter; 
};
