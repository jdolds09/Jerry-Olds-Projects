#include<iostream>
#include<gtkmm.h>
#include<string>
using namespace std;

class Check_In_Window : public Gtk::Window
{
public:
	Check_In_Window();
	~Check_In_Window();
	vector<string> get_entries();
protected:
	void on_button_enter();
	Gtk::Box m_VBox;
	Gtk::Label Year_Label;
	Gtk::Entry Year_Entry;
	Gtk::Label Month_Label;
	Gtk::Entry Month_Entry;
	Gtk::Label Day_Label;
	Gtk::Entry Day_Entry;
	Gtk::Button m_Button_Enter; 
};
