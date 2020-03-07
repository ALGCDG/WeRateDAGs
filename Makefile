  
CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I inc

all : bin/translator

src/parser.tab.cpp Include/parser.tab.hpp : src/parser.y
	bison -v -d src/parser.y -o src/parser.tab.cpp

src/lexer.yy.cpp : src/lexer.flex Include/parser.tab.hpp
	flex -o src/lexer.yy.cpp  src/lexer.flex

bin/translator : src/parser.tab.o src/lexer.yy.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/translator $^
	
clean :
	rm -f src/*.o
	rm -f bin/*
	rm -f *.tab.*
	rm -f src/*.yy.*
	rm -f *.out
	rm -f out
	rm -f *.output
