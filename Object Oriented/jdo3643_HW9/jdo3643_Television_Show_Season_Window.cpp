#include "jdo3643_Television_Show_Season_Window.h"

Television_Show_Season_Window::Television_Show_Season_Window() : m_VBox(Gtk::ORIENTATION_VERTICAL), Title_Label("Title"), Season_Number_Label("Season Number"), Year_Label("Release Year"), Producer_Label("Producer"), Director1_Label("Director 1"), Director2_Label("Director 2"), Director3_Label("Director 3"), Actor1_Label("Actor 1"), Actor2_Label("Actor 2"), Actor3_Label("Actor 3"), m_Button_Enter("Enter")
{
// Set size and title of window
	set_size_request(800, 800);
	set_title("New Television Show Season");

// Add vertical Box
	add(m_VBox);

// Title entry
	m_VBox.pack_start(Title_Label);
	Title_Entry.set_max_length(50);
	Title_Entry.select_region(0, Title_Entry.get_text_length());
    m_VBox.pack_start(Title_Entry);

// Season number entry
	m_VBox.pack_start(Season_Number_Label);
	Season_Number_Entry.set_max_length(2);
	Season_Number_Entry.select_region(0, Season_Number_Entry.get_text_length());
    m_VBox.pack_start(Season_Number_Entry);

// Year entry
	m_VBox.pack_start(Year_Label);
	Year_Entry.set_max_length(4);
	Year_Entry.select_region(0, Year_Entry.get_text_length());
    m_VBox.pack_start(Year_Entry);

// Producer entry
	m_VBox.pack_start(Producer_Label);
	Producer_Entry.set_max_length(50);
	Producer_Entry.select_region(0, Producer_Entry.get_text_length());
    m_VBox.pack_start(Producer_Entry);

// Director1 entry
	m_VBox.pack_start(Director1_Label);
	Director1_Entry.set_max_length(50);
	Director1_Entry.select_region(0, Director1_Entry.get_text_length());
    m_VBox.pack_start(Director1_Entry);

// Director2 entry
	m_VBox.pack_start(Director2_Label);
	Director2_Entry.set_max_length(50);
	Director2_Entry.select_region(0, Director2_Entry.get_text_length());
    m_VBox.pack_start(Director2_Entry);

// Director3 entry
	m_VBox.pack_start(Director3_Label);
	Director3_Entry.set_max_length(50);
	Director3_Entry.select_region(0, Director3_Entry.get_text_length());
    m_VBox.pack_start(Director3_Entry);

// Actor1 entry
	m_VBox.pack_start(Actor1_Label);
	Actor1_Entry.set_max_length(50);
	Actor1_Entry.select_region(0, Actor1_Entry.get_text_length());
    m_VBox.pack_start(Actor1_Entry);

// Actor2 entry
	m_VBox.pack_start(Actor2_Label);
	Actor2_Entry.set_max_length(50);
	Actor2_Entry.select_region(0, Actor2_Entry.get_text_length());
    m_VBox.pack_start(Actor2_Entry);

// Actor3 entry
	m_VBox.pack_start(Actor3_Label);
	Actor3_Entry.set_max_length(50);
	Actor3_Entry.select_region(0, Actor3_Entry.get_text_length());
    m_VBox.pack_start(Actor3_Entry);

// Enter button
	m_Button_Enter.signal_clicked().connect( sigc::mem_fun(*this, &Television_Show_Season_Window::on_button_enter) );
	m_VBox.pack_start(m_Button_Enter);
	m_Button_Enter.set_can_default();
	m_Button_Enter.grab_default();

	show_all_children();
}

void Television_Show_Season_Window::on_button_enter()
{
	hide();
}

vector<string> Television_Show_Season_Window::get_entries()
{
// Entry vector
	vector<string> entries;
// Get entries
	entries.push_back(Title_Entry.get_text());
	entries.push_back(Year_Entry.get_text());
	entries.push_back(Producer_Entry.get_text());
	entries.push_back(Director1_Entry.get_text());
	entries.push_back(Director2_Entry.get_text());
	entries.push_back(Director3_Entry.get_text());
	entries.push_back(Actor1_Entry.get_text());
	entries.push_back(Actor2_Entry.get_text());
	entries.push_back(Actor3_Entry.get_text());
	entries.push_back(Season_Number_Entry.get_text());
// Return entries
	return entries;
}
