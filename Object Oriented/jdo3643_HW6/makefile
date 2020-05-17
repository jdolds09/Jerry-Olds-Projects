CXX = g++
CXXFLAGS = -std=c++11

all: executable

executable:  jdo3643_main.o jdo3643_Robot.o jdo3643_Arm_Robot.o jdo3643_Mobile_Robot.o jdo3643_Extendable_Arm.o jdo3643_Powered_Arm.o
	$(CXX)	$(CXXFLAGS) jdo3643_main.o jdo3643_Robot.o jdo3643_Arm_Robot.o jdo3643_Mobile_Robot.o jdo3643_Extendable_Arm.o jdo3643_Powered_Arm.o

jdo3643_main.o: jdo3643_main.cpp jdo3643_Robot.cpp jdo3643_Arm_Robot.cpp jdo3643_Mobile_Robot.cpp jdo3643_Extendable_Arm.cpp jdo3643_Powered_Arm.cpp
	$(CXX)	$(CXXFLAGS)	-c jdo3643_main.cpp

jdo3643_Robot.o: jdo3643_Robot.h jdo3643_Robot.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Robot.cpp

jdo3643_Arm_Robot.o: jdo3643_Arm_Robot.h jdo3643_Arm_Robot.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Arm_Robot.cpp

jdo3643_Mobile_Robot.o: jdo3643_Mobile_Robot.h jdo3643_Mobile_Robot.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Mobile_Robot.cpp

jdo3643_Extendable_Arm.o: jdo3643_Extendable_Arm.h jdo3643_Extendable_Arm.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Extendable_Arm.cpp

jdo3643_Powered_Arm.o: jdo3643_Powered_Arm.h jdo3643_Powered_Arm.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Powered_Arm.cpp

clean:
	rm -f *.o a.out
