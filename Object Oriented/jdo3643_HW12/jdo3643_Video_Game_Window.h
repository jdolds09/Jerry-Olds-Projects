#include<iostream>
#include<gtkmm.h>
#include<string>
using namespace std;

class Video_Game_Window : public Gtk::Window
{
public:
	Video_Game_Window();
	~Video_Game_Window();
	vector<string> get_entries();
protected:
	void on_button_enter();
	Gtk::Box m_VBox;
	Gtk::Label Title_Label;
	Gtk::Entry Title_Entry;
	Gtk::Label Year_Label;
	Gtk::Entry Year_Entry;
	Gtk::Label Studio_Label;
	Gtk::Entry Studio_Entry;
	Gtk::Button m_Button_Enter; 
};
