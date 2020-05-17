#include "jdo3643_Video_Game_Window.h"

Video_Game_Window::Video_Game_Window() : m_VBox(Gtk::ORIENTATION_VERTICAL), Title_Label("Title"), Year_Label("Release Year"), Studio_Label("Studio"), m_Button_Enter("Enter")
{
// Set size and title of window
	set_size_request(300, 150);
	set_title("New Video Game");

// Add vertical Box
	add(m_VBox);

// Title entry
	m_VBox.pack_start(Title_Label);
	Title_Entry.set_max_length(50);
	Title_Entry.select_region(0, Title_Entry.get_text_length());
    m_VBox.pack_start(Title_Entry);

// Year entry
	m_VBox.pack_start(Year_Label);
	Year_Entry.set_max_length(4);
	Year_Entry.select_region(0, Year_Entry.get_text_length());
    m_VBox.pack_start(Year_Entry);

// Studio entry
	m_VBox.pack_start(Studio_Label);
	Studio_Entry.set_max_length(50);
	Studio_Entry.select_region(0, Studio_Entry.get_text_length());
    m_VBox.pack_start(Studio_Entry);

// Enter button
	m_Button_Enter.signal_clicked().connect( sigc::mem_fun(*this, &Video_Game_Window::on_button_enter) );
	m_VBox.pack_start(m_Button_Enter);
	m_Button_Enter.set_can_default();
	m_Button_Enter.grab_default();

	show_all_children();
}

void Video_Game_Window::on_button_enter()
{
	hide();
}

vector<string> Video_Game_Window::get_entries()
{
// Entry vector
	vector<string> entries;
// Get entries
	entries.push_back(Title_Entry.get_text());
	entries.push_back(Year_Entry.get_text());
	entries.push_back(Studio_Entry.get_text());
// Return entries
	return entries;
}
