#include "jdo3643_Movie_Window.h"

Movie_Window::Movie_Window() : m_VBox(Gtk::ORIENTATION_VERTICAL), Title_Label("Title"), Year_Label("Release Year"), Producer_Label("Producer"), Director_Label("Director"), Actor1_Label("Leading Actor 1"), Actor2_Label("Leading Actor 2"), Actor3_Label("Leading Actor 3"),  m_Button_Enter("Enter")
{
// Set size and title of window
	set_size_request(600, 600);
	set_title("New Movie");

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

// Producer entry
	m_VBox.pack_start(Producer_Label);
	Producer_Entry.set_max_length(50);
	Producer_Entry.select_region(0, Producer_Entry.get_text_length());
    m_VBox.pack_start(Producer_Entry);

// Director entry
	m_VBox.pack_start(Director_Label);
	Director_Entry.set_max_length(50);
	Director_Entry.select_region(0, Director_Entry.get_text_length());
    m_VBox.pack_start(Director_Entry);

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
	m_Button_Enter.signal_clicked().connect( sigc::mem_fun(*this, &Movie_Window::on_button_enter) );
	m_VBox.pack_start(m_Button_Enter);
	m_Button_Enter.set_can_default();
	m_Button_Enter.grab_default();

	show_all_children();
}

Movie_Window::~Movie_Window()
{
}

void Movie_Window::on_button_enter()
{
	hide();
}

vector<string> Movie_Window::get_entries()
{
// Entry vector
	vector<string> entries;
// Get entries
	entries.push_back(Title_Entry.get_text());
	entries.push_back(Year_Entry.get_text());
	entries.push_back(Producer_Entry.get_text());
	entries.push_back(Director_Entry.get_text());
	entries.push_back(Actor1_Entry.get_text());
	entries.push_back(Actor2_Entry.get_text());
	entries.push_back(Actor3_Entry.get_text());
// Return entries
	return entries;
}
