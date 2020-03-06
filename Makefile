  
CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I Include

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
	rm -f src/*.tab.*
	rm -f src/*.yy.*
	
