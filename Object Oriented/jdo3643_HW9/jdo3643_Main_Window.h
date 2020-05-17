#include <iostream>
#include<gtkmm.h>
using namespace std;

class Main_Window : public Gtk::Window
{
public:
	Main_Window();
	~Main_Window();
	int selection;
	int get_selection();
protected:
	void on_media_out_click();
	void on_bundle_out_click();
	void on_media_in_click();
	void on_bundle_in_click();
	void on_payment_click();
	void on_quit_click();
};
