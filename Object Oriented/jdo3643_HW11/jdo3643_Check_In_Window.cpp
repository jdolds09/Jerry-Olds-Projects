#include "jdo3643_Check_In_Window.h"

Check_In_Window::Check_In_Window() : m_VBox(Gtk::ORIENTATION_VERTICAL), Year_Label("Enter year media was checked in"), Month_Label("Enter month media was checked in"), Day_Label("Enter day media was checked in"), m_Button_Enter("Enter")
{
// Set size and title of window
	set_size_request(600, 300);
	set_title("Check In Media");

// Add vertical Box
	add(m_VBox);

// Year entry
	m_VBox.pack_start(Year_Label);
	Year_Entry.set_max_length(50);
	Year_Entry.select_region(0, Year_Entry.get_text_length());
    m_VBox.pack_start(Year_Entry);
	
// Month entry
	m_VBox.pack_start(Month_Label);
	Month_Entry.set_max_length(50);
	Month_Entry.select_region(0, Month_Entry.get_text_length());
    m_VBox.pack_start(Month_Entry);

// Day entry
	m_VBox.pack_start(Day_Label);
	Day_Entry.set_max_length(4);
	Day_Entry.select_region(0, Day_Entry.get_text_length());
    m_VBox.pack_start(Day_Entry);

// Enter button
	m_Button_Enter.signal_clicked().connect( sigc::mem_fun(*this, &Check_In_Window::on_button_enter) );
	m_VBox.pack_start(m_Button_Enter);
	m_Button_Enter.set_can_default();
	m_Button_Enter.grab_default();

	show_all_children();
}

Check_In_Window::~Check_In_Window()
{

}

void Check_In_Window::on_button_enter()
{
	hide();
}

vector<string> Check_In_Window::get_entries()
{
// Entry vector
	vector<string> entries;
// Get entries
	entries.push_back(Year_Entry.get_text());
	entries.push_back(Month_Entry.get_text());
	entries.push_back(Day_Entry.get_text());
// Return entries
	return entries;
}
