#CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -std=c++11
#
#OBJS =		Test.o
#
#LIBS =
#
#TARGET =	Test
#
#LDFLAGS =   -lpthread
#
#$(TARGET):	$(OBJS)
#	$(CXX) -o $(TARGET) $(OBJS) $(LIBS) $(LDFLAGS)
#
#all:	$(TARGET)
#
#clean:
#	rm -f $(OBJS) $(TARGET)

CXXINCFLAGS := -std=c++11
CXXFLAGS := -Wall -g $(CXXINCFLAGS)
LDFLAGS := -lpthread
SRC := $(wildcard *.cpp)
TARGET := $(SRC:%.cpp=bin/%)

all: | bin $(TARGET)

bin/% : %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

bin:
	mkdir bin

clean:
	rm -fr bin/