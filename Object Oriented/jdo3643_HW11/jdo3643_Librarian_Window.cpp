#include "jdo3643_Librarian_Window.h"

Librarian_Window::Librarian_Window() : m_VBox(Gtk::ORIENTATION_VERTICAL), Name_Label("Librarian Name"), m_Button_Enter("Enter")
{
// Set size and title of window
	set_size_request(400, 200);
	set_title("New Librarian");

// Add vertical Box
	add(m_VBox);

// Name entry
	m_VBox.pack_start(Name_Label);
	Name_Entry.set_max_length(50);
	Name_Entry.select_region(0, Name_Entry.get_text_length());
    m_VBox.pack_start(Name_Entry);
	

// Enter button
	m_Button_Enter.signal_clicked().connect( sigc::mem_fun(*this, &Librarian_Window::on_button_enter) );
	m_VBox.pack_start(m_Button_Enter);
	m_Button_Enter.set_can_default();
	m_Button_Enter.grab_default();

	show_all_children();
}

Librarian_Window::~Librarian_Window()
{
}

void Librarian_Window::on_button_enter()
{
	hide();
}

string Librarian_Window::get_name()
{
	return Name_Entry.get_text();
}
