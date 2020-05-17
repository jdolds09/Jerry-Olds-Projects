CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: build

COMMON_H = header/Player.h

COMMON_CPP = src/Player.cpp

build:
	${MAKE} 300
	${MAKE} 290
	${MAKE} 280

300: src/300main.cpp ${COMMON_H} ${COMMON_CPP} 
	${CXX} -o $@ ${CXXFLAGS} $^

290: src/290main.cpp ${COMMON_H} ${COMMON_CPP} 
	${CXX} -o $@ ${CXXFLAGS} $^

280: src/280main.cpp ${COMMON_H} ${COMMON_CPP} 
	${CXX} -o $@ ${CXXFLAGS} $^

clean:
	rm -f 300 290 280
