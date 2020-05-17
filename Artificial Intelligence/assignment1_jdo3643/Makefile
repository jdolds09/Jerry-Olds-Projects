CXX = g++
CXXFLAGS = -Wall

all: build

COMMON_H = node.h

COMMON_CPP = node.cpp

build:
	${MAKE} find_route

find_route: find_route.cpp ${COMMON_H} ${COMMON_CPP}
	${CXX} -o $@ ${CXXFLAGS} $^

clean:
	rm -f find_route

