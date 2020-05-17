CXX = g++
CXXFLAGS = -std=c++11

1: executable1

2: executable2

executable1:  jdo3643_main1.o jdo3643_Robot.o jdo3643_Arm_Robot.o jdo3643_Mobile_Robot.o jdo3643_Extendable_Arm.o jdo3643_Powered_Arm.o jdo3643_Super_Arm.o jdo3643_Mobile_Arm.o
	$(CXX)	$(CXXFLAGS) jdo3643_main1.o jdo3643_Robot.o jdo3643_Arm_Robot.o jdo3643_Mobile_Robot.o jdo3643_Extendable_Arm.o jdo3643_Powered_Arm.o jdo3643_Super_Arm.o jdo3643_Mobile_Arm.o

executable2:  jdo3643_main2.o jdo3643_Robot.o jdo3643_Arm_Robot.o jdo3643_Mobile_Robot.o jdo3643_Extendable_Arm.o jdo3643_Powered_Arm.o jdo3643_Super_Arm.o jdo3643_Mobile_Arm.o
	$(CXX)	$(CXXFLAGS) jdo3643_main2.o jdo3643_Robot.o jdo3643_Arm_Robot.o jdo3643_Mobile_Robot.o jdo3643_Extendable_Arm.o jdo3643_Powered_Arm.o jdo3643_Super_Arm.o jdo3643_Mobile_Arm.o

jdo3643_main1.o: jdo3643_main1.cpp jdo3643_Robot.cpp jdo3643_Arm_Robot.cpp jdo3643_Mobile_Robot.cpp jdo3643_Extendable_Arm.cpp jdo3643_Powered_Arm.cpp jdo3643_Super_Arm.cpp jdo3643_Mobile_Arm.cpp
	$(CXX)	$(CXXFLAGS)	-c jdo3643_main1.cpp

jdo3643_main2.o: jdo3643_main2.cpp jdo3643_Robot.cpp jdo3643_Arm_Robot.cpp jdo3643_Mobile_Robot.cpp jdo3643_Extendable_Arm.cpp jdo3643_Powered_Arm.cpp jdo3643_Super_Arm.cpp jdo3643_Mobile_Arm.cpp
	$(CXX)	$(CXXFLAGS)	-c jdo3643_main2.cpp

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

jdo3643_Super_Arm.o: jdo3643_Super_Arm.h jdo3643_Super_Arm.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Super_Arm.cpp

jdo3643_Mobile_Arm.o: jdo3643_Mobile_Arm.h jdo3643_Mobile_Arm.cpp
	$(CXX) $(CXXFLAGS) -c jdo3643_Mobile_Arm.cpp

clean:
	rm -f *.o a.out
