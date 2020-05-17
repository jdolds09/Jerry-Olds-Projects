#ifndef JDO3643_BUNDLE_H
#define JDO3643_BUNDLE_H

#include "jdo3643_Media.h"

class Bundle
{
private:
	string name;
	vector<Media> medias;
	bool checked_out = false;
public:
	Bundle();
	Bundle(string n, bool co);
	void add_to_bundle(Media media);
	void remove_from_bundle(int id);
};

#endif