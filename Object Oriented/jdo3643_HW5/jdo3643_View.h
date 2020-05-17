#include "jdo3643_Transaction_List.h"

class View
{
private:
	Transaction_List& transaction_list;
public:
	View(Transaction_List& tl) : transaction_list(tl) {};
	string get_menu();
	string view_transactions();
	string average();
	string bonus();
// ADD TRANSACTION PROMPTS
	string prompt_for_name();
	string prompt_for_price();
	string prompt_for_year();
	string prompt_for_month();
	string prompt_for_day();
	string prompt_for_hour();
	string prompt_for_minute();
	string prompt_for_second();
// DELETE TRANSACTION PROMPTS
	string delete_prompt();
	string delete_year_prompt();
	string delete_month_prompt();
	string delete_day_prompt();
	string delete_hour_prompt();
	string delete_minute_prompt();
	string delete_second_prompt();
	string delete_name_prompt();
};
