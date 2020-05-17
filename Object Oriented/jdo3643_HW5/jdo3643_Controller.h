#include "jdo3643_View.h"

class Controller
{
private:
	Transaction_List& transaction_list;
	View& view;
public:
	Controller(Transaction_List& tl, View& v) : transaction_list(tl), view(v) {};
	void cli();
	void execute_cmd(int cmd2);
	void new_transaction();
	void delete_transaction();
	void average();
	void bonus();
};
