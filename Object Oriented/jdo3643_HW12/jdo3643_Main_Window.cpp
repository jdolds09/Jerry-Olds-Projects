#include "jdo3643_Main_Window.h"

Main_Window::Main_Window()
{
// Set size and title
	set_size_request(400,200);
	set_title("Main Menu");

// Vertical box
	Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	add(*vbox);

// Menu Bar
	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
	Gtk::MenuItem *menuitem_menu = Gtk::manage(new Gtk::MenuItem("_Menu", true));
	menubar->append(*menuitem_menu);
	Gtk::Menu *menu_submenu = Gtk::manage(new Gtk::Menu());
	menuitem_menu->set_submenu(*menu_submenu);

// Check out media
	Gtk::MenuItem *menuitem_media_out = Gtk::manage(new Gtk::MenuItem("_Check out media", true));
	menuitem_media_out->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_media_out_click));
	menu_submenu->append(*menuitem_media_out);

// Check out bundle
	Gtk::MenuItem *menuitem_bundle_out = Gtk::manage(new Gtk::MenuItem("_Check out bundle", true));
	menuitem_bundle_out->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_bundle_out_click));
	menu_submenu->append(*menuitem_bundle_out);

// Check in media
	Gtk::MenuItem *menuitem_media_in = Gtk::manage(new Gtk::MenuItem("_Check in media", true));
	menuitem_media_in->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_media_in_click));
	menu_submenu->append(*menuitem_media_in);

// Check in bundle
	Gtk::MenuItem *menuitem_bundle_in = Gtk::manage(new Gtk::MenuItem("_Check in bundle", true));
	menuitem_bundle_in->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_bundle_in_click));
	menu_submenu->append(*menuitem_bundle_in);

// Make payment
	Gtk::MenuItem *menuitem_payment = Gtk::manage(new Gtk::MenuItem("_Make payment", true));
	menuitem_payment->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_payment_click));
	menu_submenu->append(*menuitem_payment);

// See checked out items
	Gtk::MenuItem *menuitem_checked_out = Gtk::manage(new Gtk::MenuItem("_Checked out items", true));
	menuitem_checked_out->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_checked_out_click));
	menu_submenu->append(*menuitem_checked_out);


// Quit
	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
	menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_quit_click));
	menu_submenu->append(*menuitem_quit);


	vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
	vbox->show_all();
}

Main_Window::~Main_Window()
{
}

void Main_Window::on_media_out_click()
{
	selection = 1;
	hide();
}

void Main_Window::on_bundle_out_click()
{
	selection = 2;
	hide();
}

void Main_Window::on_media_in_click()
{
	selection = 3;
	hide();
}

void Main_Window::on_bundle_in_click()
{
	selection = 4;
	hide();
}

void Main_Window::on_payment_click()
{
	selection = 5;
	hide();
}

void Main_Window::on_checked_out_click()
{
	selection = 6;
	hide();
}


void Main_Window::on_quit_click()
{
	selection = 7;
	hide();
}

int Main_Window::get_selection()
{
	return selection;
}
