#include "Controller.h"

int main()
{
// Objects
	Transaction_List list{};
	View view{list};
	Controller controller{ list, view };
// Load save file
	list.load();
// Call cli
	controller.cli();
// End of program
	return 0;
}