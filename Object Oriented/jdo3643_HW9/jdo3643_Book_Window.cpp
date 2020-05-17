#include "jdo3643_Book_Window.h"

Book_Window::Book_Window() : m_VBox(Gtk::ORIENTATION_VERTICAL), Title_Label("Title"), Author_Label("Author"), Year_Label("Copyright Year"), m_Button_Enter("Enter")
{
// Set size and title of window
	set_size_request(600, 300);
	set_title("New Book");

// Add vertical Box
	add(m_VBox);

// Title entry
	m_VBox.pack_start(Title_Label);
	Title_Entry.set_max_length(50);
	Title_Entry.select_region(0, Title_Entry.get_text_length());
    m_VBox.pack_start(Title_Entry);
	
// Author entry
	m_VBox.pack_start(Author_Label);
	Author_Entry.set_max_length(50);
	Author_Entry.select_region(0, Author_Entry.get_text_length());
    m_VBox.pack_start(Author_Entry);

// Year entry
	m_VBox.pack_start(Year_Label);
	Year_Entry.set_max_length(4);
	Year_Entry.select_region(0, Year_Entry.get_text_length());
    m_VBox.pack_start(Year_Entry);

// Enter button
	m_Button_Enter.signal_clicked().connect( sigc::mem_fun(*this, &Book_Window::on_button_enter) );
	m_VBox.pack_start(m_Button_Enter);
	m_Button_Enter.set_can_default();
	m_Button_Enter.grab_default();

	show_all_children();
}

void Book_Window::on_button_enter()
{
	hide();
}

vector<string> Book_Window::get_entries()
{
// Entry vector
	vector<string> entries;
// Get entries
	entries.push_back(Title_Entry.get_text());
	entries.push_back(Author_Entry.get_text());
	entries.push_back(Year_Entry.get_text());
// Return entries
	return entries;
}
