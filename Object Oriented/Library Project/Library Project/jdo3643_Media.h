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
	bool checked_out = false;
protected:
	int id_number;
	string call_number;
	string title;
	string genre;
	Book book;
	Movie movie;
	Music_Album music_album;
	Television_Show_Season television_show_season;
	Video_Game video_game;
public:
	Media();
	Media(int id, string cn, string t, string g);
	void media_information(string g, string t);
	void set_check(bool c);
	int get_id_number();
	string get_title();
	string get_genre();
	bool get_checked_out();
	Book get_book();
	Movie get_movie();
	Music_Album get_music_album();
	Television_Show_Season get_television_show_season();
	Video_Game get_video_game();
};

#endif