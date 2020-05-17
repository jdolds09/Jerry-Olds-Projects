#include "jdo3643_View.h"

class Controller
{
public:
	int customer_select(vector<Customer> c);
	int librarian_select(vector<Librarian> l);
	int menu_select();
	int media_select(vector<Media> m);
	int bundle_select();
	int media_check_in_select(vector<Media> m);
	int bundle_check_in_select(vector<Bundle> b);
private:
};
