#ifndef JDO3643_VIEW_H
#define JDO3643_VIEW_H

#include "jdo3643_Library.h"

class View : public Library
{
public:
	void title();
	void customer_list(vector<Customer> c);
	void librarian_list(vector<Librarian> l);
	void menu();
	void media_catalog();
	void book_catalog(vector<Media> b);
	void movie_catalog(vector<Media> m);
	void music_album_catalog(vector<Media> ma);
	void television_show_season_catalog(vector<Media> tss);
	void video_game_catalog(vector<Media> vg);
	void checked_out(Media m, Date cod, Date dd, string n);
	void bundle_catalog();
	void checked_out_medias_list(Customer c, vector<Media> m);
	void checked_out_bundles_list(Customer c, vector<Bundle> b);
	void checked_out_items(vector<Customer> customers);
private:
};

#endif
