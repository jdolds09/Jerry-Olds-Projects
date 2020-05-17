#ifndef JDO3643_MEDIA_H
#define JDO3643_MEDIA_H

#include "jdo3643_Television_Show_Season.h"
#include "jdo3643_Music_Album.h"
#include "jdo3643_Video_Game.h"
#include "jdo3643_Movie.h"
#include "jdo3643_Book.h"

class Media
{
private:
	bool checked_out;
protected:
	int id_number;
	string call_number;
	string title;
	string genre;
public:
	Media(int id, string cn, string t, string g);
	void media_information(string g);
	int get_id_number();
};

#endif