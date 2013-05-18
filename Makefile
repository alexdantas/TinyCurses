# This Makefile builds the library along with all the tests

CC  = gcc
CXX = g++

CFLAGS   = -Wall -O3 `sdl-config --cflags`
CXXFLAGS = $(CFLAGS)

LDFLAGS  = `sdl-config --libs` -lSDL_ttf
INCLUDE  = -I"/usr/include/SDL"

all: TinyCurses.o TinyCursesLib test/test

TinyCurses.o: TinyCurses.cpp
	$(CXX) TinyCurses.cpp -c -o TinyCurses.o $(CXXFLAGS) $(INCLUDE) $(LDFLAGS)

TinyCursesLib: TinyCurses.o
	# Building library...
	$(CXX) -shared $(CXXFLAGS) $(INCLUDE) -o TinyCurses.so $(LDFLAGS)

test/test:
	# Building test on src/test...
	$(CXX) $(CXXFLAGS) $(INCLUDE) TinyCurses.cpp test/test.cpp -o test/test $(LDFLAGS)

clean:
	# Cleaning...
	rm -f TinyCurses.o TinyCurses.so

