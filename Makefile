CC := g++
CXXINCFLAGS := -std=c++11
CXXFLAGS := -Wall -g $(CXXINCFLAGS)
LDFLAGS := -lpthread
SRC := $(wildcard *.cpp)
TARGET := $(SRC:%.cpp=bin/%)

all: | bin $(TARGET)

bin/% : %.cpp
	$(CC) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

bin:
	mkdir bin

clean:
	rm -fr bin/
