#include<iostream>
#include<gtkmm.h>
#include<string>
using namespace std;

class Book_Window : public Gtk::Window
{
public:
	Book_Window();
	~Book_Window();
	vector<string> get_entries();
protected:
	void on_button_enter();
	Gtk::Box m_VBox;
	Gtk::Label Title_Label;
	Gtk::Entry Title_Entry;
	Gtk::Label Author_Label;
	Gtk::Entry Author_Entry;
	Gtk::Label Year_Label;
	Gtk::Entry Year_Entry;
	Gtk::Button m_Button_Enter; 
};
