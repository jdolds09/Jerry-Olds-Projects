CXX = g++
CXXFLAGS = -std=c++11

all: executable

executable:  jdo3643_main.o jdo3643_Book.o jdo3643_Bundle.o jdo3643_Customer.o jdo3643_Date.o jdo3643_Librarian.o jdo3643_Library.o jdo3643_Media.o jdo3643_Movie.o jdo3643_Music_Album.o jdo3643_Television_Show_Season.o jdo3643_Transaction.o jdo3643_Video_Game.o
	$(CXX)	$(CXXFLAGS) jdo3643_main.o jdo3643_Book.o jdo3643_Bundle.o jdo3643_Customer.o jdo3643_Date.o jdo3643_Librarian.o jdo3643_Library.o jdo3643_Media.o jdo3643_Movie.o jdo3643_Music_Album.o jdo3643_Television_Show_Season.o jdo3643_Transaction.o jdo3643_Video_Game.o

jdo3643_main.o: jdo3643_main.cpp jdo3643_Book.cpp jdo3643_Bundle.cpp jdo3643_Customer.cpp jdo3643_Date.cpp jdo3643_Librarian.cpp jdo3643_Library.cpp jdo3643_Media.cpp jdo3643_Movie.cpp jdo3643_Music_Album.cpp jdo3643_Television_Show_Season.cpp jdo3643_Transaction.cpp jdo3643_Video_Game.cpp
	$(CXX)	$(CXXFLAGS)	-c jdo3643_main.cpp

jdo3643_Book.o: jdo3643_Book.h jdo3643_Book.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Book.cpp

jdo3643_Bundle.o: jdo3643_Bundle.h jdo3643_Bundle.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Bundle.cpp

jdo3643_Customer.o: jdo3643_Customer.h jdo3643_Customer.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Customer.cpp

jdo3643_Date.o: jdo3643_Date.h jdo3643_Date.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Date.cpp

jdo3643_Librarian.o: jdo3643_Librarian.h jdo3643_Librarian.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Librarian.cpp

jdo3643_Library.o: jdo3643_Library.h jdo3643_Library.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Library.cpp

jdo3643_Media.o: jdo3643_Media.h jdo3643_Media.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Media.cpp

jdo3643_Movie.o: jdo3643_Movie.h jdo3643_Movie.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Movie.cpp

jdo3643_Music_Album.o: jdo3643_Music_Album.h jdo3643_Music_Album.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Music_Album.cpp

jdo3643_Television_Show_Season.o: jdo3643_Television_Show_Season.h jdo3643_Television_Show_Season.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Television_Show_Season.cpp

jdo3643_Transaction.o: jdo3643_Transaction.h jdo3643_Transaction.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Transaction.cpp

jdo3643_Video_Game.o: jdo3643_Video_Game.h jdo3643_Video_Game.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Video_Game.cpp

clean:
	rm -f *.o a.out
