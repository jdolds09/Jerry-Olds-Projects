#include<iostream>
#include<gtkmm.h>
#include<string>
using namespace std;

class Music_Album_Window : public Gtk::Window
{
public:
	Music_Album_Window();
	~Music_Album_Window();
	vector<string> get_entries();
protected:
	void on_button_enter();
	Gtk::Box m_VBox;
	Gtk::Label Title_Label;
	Gtk::Entry Title_Entry;
	Gtk::Label Year_Label;
	Gtk::Entry Year_Entry;
	Gtk::Label Artist_Label;
	Gtk::Entry Artist_Entry;
	Gtk::Label Track1_Label;
	Gtk::Entry Track1_Entry;
	Gtk::Label Track2_Label;
	Gtk::Entry Track2_Entry;
	Gtk::Label Track3_Label;
	Gtk::Entry Track3_Entry;
	Gtk::Button m_Button_Enter; 
};
