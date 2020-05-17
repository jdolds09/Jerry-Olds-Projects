#include "jdo3643_Music_Album_Window.h"

Music_Album_Window::Music_Album_Window() : m_VBox(Gtk::ORIENTATION_VERTICAL), Title_Label("Title"), Year_Label("Release Year"), Artist_Label("Artist"), Track1_Label("Track 1"), Track2_Label("Track 2"), Track3_Label("Track 3"),  m_Button_Enter("Enter")
{
// Set size and title of window
	set_size_request(600, 600);
	set_title("New Music Album");

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

// Artist entry
	m_VBox.pack_start(Artist_Label);
	Artist_Entry.set_max_length(50);
	Artist_Entry.select_region(0, Artist_Entry.get_text_length());
    m_VBox.pack_start(Artist_Entry);

// Track1 entry
	m_VBox.pack_start(Track1_Label);
	Track1_Entry.set_max_length(50);
	Track1_Entry.select_region(0, Track1_Entry.get_text_length());
    m_VBox.pack_start(Track1_Entry);

// Track2 entry
	m_VBox.pack_start(Track2_Label);
	Track2_Entry.set_max_length(50);
	Track2_Entry.select_region(0, Track2_Entry.get_text_length());
    m_VBox.pack_start(Track2_Entry);

// Track3 entry
	m_VBox.pack_start(Track3_Label);
	Track3_Entry.set_max_length(50);
	Track3_Entry.select_region(0, Track3_Entry.get_text_length());
    m_VBox.pack_start(Track3_Entry);

// Enter button
	m_Button_Enter.signal_clicked().connect( sigc::mem_fun(*this, &Music_Album_Window::on_button_enter) );
	m_VBox.pack_start(m_Button_Enter);
	m_Button_Enter.set_can_default();
	m_Button_Enter.grab_default();

	show_all_children();
}

Music_Album_Window::~Music_Album_Window()
{
}

void Music_Album_Window::on_button_enter()
{
	hide();
}

vector<string> Music_Album_Window::get_entries()
{
// Entry vector
	vector<string> entries;
// Get entries
	entries.push_back(Title_Entry.get_text());
	entries.push_back(Year_Entry.get_text());
	entries.push_back(Artist_Entry.get_text());
	entries.push_back(Track1_Entry.get_text());
	entries.push_back(Track2_Entry.get_text());
	entries.push_back(Track3_Entry.get_text());
// Return entries
	return entries;
}
