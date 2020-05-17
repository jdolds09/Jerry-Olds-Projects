CXX = g++
RM = -rm

OSPL_LIBS = -lddskernel -ldcpssacpp -lboost_system
LIBS = -L${OSPL_HOME}/lib ${OSPL_LIBS} \
-lmenu -lform -lncurses

CFLAGS = -DDEBUG_PRINT -DDEBUG_STATES -Wall -O0 -g -I. \
-I./include \
-I${OSPL_HOME}/include/dcps/C++/SACPP \
-I${OSPL_HOME}/include/sys \
-I./standalone \
-I${OSPL_HOME}/include

CXXFLAGS = -std=c++11

all: build

IDL_GENERATED_DIR = standalone
DIRS = obj ${IDL_GENERATED_DIR}

IDL_GENERATED_H = \
${IDL_GENERATED_DIR}/ccpp_TSN.h \
${IDL_GENERATED_DIR}/TSNDcps.h \
${IDL_GENERATED_DIR}/TSNDcps_impl.h \
${IDL_GENERATED_DIR}/TSN.h \
${IDL_GENERATED_DIR}/TSNSplDcps.h

IDL_GENERATED_CPP = \
${IDL_GENERATED_DIR}/TSN.cpp \
${IDL_GENERATED_DIR}/TSNDcps.cpp \
${IDL_GENERATED_DIR}/TSNDcps_impl.cpp \
${IDL_GENERATED_DIR}/TSNSplDcps.cpp

IDL_GENERATED = ${IDL_GENERATED_H} ${IDL_GENERATED_CPP}

genIdl: idl/TSN.idl
	${OSPL_HOME}/bin/idlpp -l cpp idl/TSN.idl -d ${IDL_GENERATED_DIR}

COMMON_CPP = src/CheckStatus.cpp src/DDSEntityManager.cpp

COMMON_H = include/CheckStatus.h include/DDSEntityManager.h include/DDSHelper.h

IGNORE_CPP = src/tsn.cpp

JSON = lib/json11/json11.cpp

OBJECTS = $(patsubst %.cpp, %.o, $(filter-out ${IGNORE_CPP}, $(filter-out ${COMMON_CPP}, $(wildcard src/*.cpp))))
OBJECTS := $(OBJECTS:src/%=obj/%)

build:
	${MAKE} genIdl
	${MAKE} tsn

tsn: ${IDL_GENERATED} ${OBJECTS} src/tsn.cpp ${COMMON_H} ${COMMON_CPP} ${JSON}
	${CXX} -o $@ ${CFLAGS} ${CXXFLAGS} $^ ${LIBS}

${OBJECTS}: obj/%.o : src/%.cpp
	${CXX} -c $^ -o $@ ${CFLAGS} ${CXXFLAGS}

TESTS = $(wildcard tests/*.cpp)

testcases: include/TestCases.h ${TESTS} ${IDL_GENERATED_H} ${IDL_GENERATED_CPP} ${OBJECTS} ${COMMON_H} ${COMMON_CPP}
	${CXX} $^ -o $@ -lboost_unit_test_framework ${CFLAGS} ${CXXFLAGS} ${LIBS}
	./testcases

clean:
	${RM} -f tsn testcases ${OBJECTS}
	${RM} -f ${IDL_GENERATED_H} ${IDL_GENERATED_CPP}
	${RM} -f ospl-error.log ospl-info.log

$(shell mkdir -p $(DIRS))
