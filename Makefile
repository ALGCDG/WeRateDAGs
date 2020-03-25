  
CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I inc

all : bin/compiler src/wrapper.sh
	cp src/wrapper.sh bin/c_compiler
	chmod u+x bin/c_compiler

src/parser.tab.cpp Include/parser.tab.hpp : src/parser.y
	bison -v -d src/parser.y -o src/parser.tab.cpp

src/lexer.yy.cpp : src/lexer.flex Include/parser.tab.hpp
	flex -o src/lexer.yy.cpp  src/lexer.flex

# src/ast_context2.o : src/ast_context2.cpp
# 	g++ $(CPPFLAGS) -o src/ast_context2.o $^

# src/ASTProc.o : src/ASTProc.cpp src/ast_context2.o src/ast_allnodes.o
# 	g++ $(CPPFLAGS) -o src/ASTProc.o $^

bin/compiler : src/parser.tab.o src/lexer.yy.o src/compiler.o src/ast_allnodes.o src/ASTProc.o src/ast_context2.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/compiler $^
	
clean :
	rm -f src/*.o
	rm -f bin/*
	rm -f src/*.tab.*
	rm -f src/*.yy.*
	rm -f *.out
	rm -f out
	rm -f src/*.output
	rm -f inc/*.hpp.gch
	rm -f src/*.swo
	rm -f *.core