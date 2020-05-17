#include "jdo3643_Bundle.h"

Bundle::Bundle()
{

}

Bundle::Bundle(string n)
{
	name = n;
}

void Bundle::add_to_bundle(Media media)
{
	medias.push_back(media);
}

void Bundle::remove_from_bundle(int id)
{
	int num;
	for (int i = 0; i < medias.size(); i++)
	{
		num = medias[i].get_id_number();
		if (num == id)
			medias.erase(medias.begin() + i);
	}
}

void Bundle::set_check(bool c)
{
	checked_out = c;
}

string Bundle::get_bundle_name()
{
	return name;
}