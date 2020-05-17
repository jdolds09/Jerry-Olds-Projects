CXX = g++
CXXFLAGS = -std=c++11

all: executable

executable:  jdo3643_main.o jdo3643_Date.o jdo3643_Transaction.o jdo3643_Transaction_List.o jdo3643_View.o jdo3643_Controller.o
	$(CXX)	$(CXXFLAGS) jdo3643_main.o jdo3643_Date.o jdo3643_Transaction.o jdo3643_Transaction_List.o jdo3643_View.o jdo3643_Controller.o

jdo3643_main.o: jdo3643_main.cpp jdo3643_Date.cpp jdo3643_Transaction.cpp jdo3643_Transaction_List.cpp jdo3643_View.cpp jdo3643_Controller.cpp
	$(CXX)	$(CXXFLAGS)	-c jdo3643_main.cpp

jdo3643_Date.o: jdo3643_Date.h jdo3643_Date.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Date.cpp

jdo3643_Transaction.o: jdo3643_Transaction.h jdo3643_Transaction.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Transaction.cpp

jdo3643_Transaction_List.o: jdo3643_Transaction_List.h jdo3643_Transaction_List.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Transaction_List.cpp

jdo3643_View.o: jdo3643_View.h jdo3643_View.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_View.cpp

jdo3643_Controller.o: jdo3643_Controller.h jdo3643_Controller.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Controller.cpp

clean:
	rm -f *.o a.out
