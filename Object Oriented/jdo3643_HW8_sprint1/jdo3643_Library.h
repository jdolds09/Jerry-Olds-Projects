#include "jdo3643_Media.h"
#include "jdo3643_Bundle.h"
#include "jdo3643_Customer.h"
#include "jdo3643_Librarian.h"
#include "jdo3643_Transaction.h"

class Library : public Bundle, public Transaction
{
private:
	vector<Media> medias;
	vector<Transaction> transactions;
	vector<Customer> customers;
	vector<Librarian> librarians;
	vector<Bundle> bundles;
public:
	Library();
	void create_new_media(int id, string cn, string t, string g);
	void create_new_bundle(string n, vector<Media> medias);
	void create_new_librarian(string n, int i);
	void create_new_customer(string n, int i, unsigned int p, string e);
	void create_new_transaction();
	void save(string file_name);
	void load(string file_name);
};
