#include<iostream>
#include<gtkmm.h>
#include<string>
using namespace std;

class Movie_Window : public Gtk::Window
{
public:
	Movie_Window();
	~Movie_Window();
	vector<string> get_entries();
protected:
	void on_button_enter();
	Gtk::Box m_VBox;
	Gtk::Label Title_Label;
	Gtk::Entry Title_Entry;
	Gtk::Label Year_Label;
	Gtk::Entry Year_Entry;
	Gtk::Label Producer_Label;
	Gtk::Entry Producer_Entry;
	Gtk::Label Director_Label;
	Gtk::Entry Director_Entry;
	Gtk::Label Actor1_Label;
	Gtk::Entry Actor1_Entry;
	Gtk::Label Actor2_Label;
	Gtk::Entry Actor2_Entry;
	Gtk::Label Actor3_Label;
	Gtk::Entry Actor3_Entry;
	Gtk::Button m_Button_Enter; 
};
