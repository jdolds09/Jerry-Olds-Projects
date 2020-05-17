#include "jdo3643_Customer_Window.h"

Customer_Window::Customer_Window() : m_VBox(Gtk::ORIENTATION_VERTICAL), Name_Label("Customer Name"), Phone_Label("Phone Number"), Email_Label("Email"), m_Button_Enter("Enter")
{
// Set size and title of window
	set_size_request(600, 300);
	set_title("New Customer");

// Add vertical Box
	add(m_VBox);

// Name entry
	m_VBox.pack_start(Name_Label);
	Name_Entry.set_max_length(50);
	Name_Entry.select_region(0, Name_Entry.get_text_length());
    m_VBox.pack_start(Name_Entry);
	
// Phone number entry
	m_VBox.pack_start(Phone_Label);
	Phone_Entry.set_max_length(11);
	Phone_Entry.select_region(0, Phone_Entry.get_text_length());
    m_VBox.pack_start(Phone_Entry);

// Email entry
	m_VBox.pack_start(Email_Label);
	Email_Entry.set_max_length(50);
	Email_Entry.select_region(0, Email_Entry.get_text_length());
    m_VBox.pack_start(Email_Entry);

// Enter button
	m_Button_Enter.signal_clicked().connect( sigc::mem_fun(*this, &Customer_Window::on_button_enter) );
	m_VBox.pack_start(m_Button_Enter);
	m_Button_Enter.set_can_default();
	m_Button_Enter.grab_default();

	show_all_children();
}

void Customer_Window::on_button_enter()
{
	hide();
}

vector<string> Customer_Window::get_entries()
{
// Entry vector
	vector<string> entries;
// Get entries
	entries.push_back(Name_Entry.get_text());
	entries.push_back(Phone_Entry.get_text());
	entries.push_back(Email_Entry.get_text());
// Return entries
	return entries;
}
