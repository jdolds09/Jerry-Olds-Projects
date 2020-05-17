#include<iostream>
#include<gtkmm.h>
#include<string>
using namespace std;

class Television_Show_Season_Window : public Gtk::Window
{
public:
	Television_Show_Season_Window();
	~Television_Show_Season_Window();
	vector<string> get_entries();
protected:
	void on_button_enter();
	Gtk::Box m_VBox;
	Gtk::Label Title_Label;
	Gtk::Entry Title_Entry;
	Gtk::Label Season_Number_Label;
	Gtk::Entry Season_Number_Entry;
	Gtk::Label Year_Label;
	Gtk::Entry Year_Entry;
	Gtk::Label Producer_Label;
	Gtk::Entry Producer_Entry;
	Gtk::Label Director1_Label;
	Gtk::Entry Director1_Entry;
	Gtk::Label Director2_Label;
	Gtk::Entry Director2_Entry;
	Gtk::Label Director3_Label;
	Gtk::Entry Director3_Entry;
	Gtk::Label Actor1_Label;
	Gtk::Entry Actor1_Entry;
	Gtk::Label Actor2_Label;
	Gtk::Entry Actor2_Entry;
	Gtk::Label Actor3_Label;
	Gtk::Entry Actor3_Entry;
	Gtk::Button m_Button_Enter; 
};
