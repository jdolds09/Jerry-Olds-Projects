#include "jdo3643_Customer.h"
#include<gtkmm.h>

class Existing_Customer_Window : public Gtk::Window
{
public:
	Existing_Customer_Window(vector<Customer> c);
	void on_combo_changed();
	int get_selection();
protected:
	class ModelColumns : public Gtk::TreeModel::ColumnRecord
	{
	public:
		ModelColumns()
		{ add(m_col_id); add(m_col_name); }
		Gtk::TreeModelColumn<int> m_col_id;
		Gtk::TreeModelColumn<Glib::ustring> m_col_name;
	};

	ModelColumns m_Columns;

	Gtk::ComboBox m_Combo;
	Gtk::CellRendererText m_cell;
    Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
};
