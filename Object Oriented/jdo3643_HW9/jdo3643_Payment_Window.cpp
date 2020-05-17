#include "jdo3643_Payment_Window.h"

Payment_Window::Payment_Window() : m_VBox(Gtk::ORIENTATION_VERTICAL), Payment_Label("Enter Amount"), m_Button_Enter("Enter")
{
// Set size and title of window
	set_size_request(400, 200);
	set_title("Make Payment");

// Add vertical Box
	add(m_VBox);

// Payment entry
	m_VBox.pack_start(Payment_Label);
	Payment_Entry.set_max_length(50);
	Payment_Entry.select_region(0, Payment_Entry.get_text_length());
    m_VBox.pack_start(Payment_Entry);

// Enter button
	m_Button_Enter.signal_clicked().connect( sigc::mem_fun(*this, &Payment_Window::on_button_enter) );
	m_VBox.pack_start(m_Button_Enter);
	m_Button_Enter.set_can_default();
	m_Button_Enter.grab_default();

	show_all_children();
}

void Payment_Window::on_button_enter()
{
	hide();
}

string Payment_Window::get_entry()
{
	return Payment_Entry.get_text();
}
