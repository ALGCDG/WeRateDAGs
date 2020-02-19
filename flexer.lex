%option noyywrap

%{
#include "tokens.hpp"
extern "C" int fileno(FILE *stream); // fixing bug in flex
%}


D [0-9]
A [a-zA-Z_]
P [a-zA-Z_0-9]
H [a-fA-F0-9]

Type [int]
Operator [+,-,*,/,&,&&,|,||]

%%

"int"
    {
        /*
        Keywords
        type data: int char etc... but also unsigned, struct, enum
        structures: if, else, for, while, do, return, break continue case
        builtin functions: sizeof
        luckily not flexible
        */
		return KEYWORD(INT);
	}

AP*	{
		return IDENTIFIER;
	}

-?{D}+\.?{D}*   {
		return CONSTANT;
	}

\'.\'	{
		/*
		Char
        also returns a constant
		*/
        return CONSTANT;
	}

P*	{
        /*
        Operator
        [ ] ( ) . -> ++ -- & * + - ~ ! i sizeof / % << >> < > <= >= == != ^ | && || ? : = *= /= %= += -= <<= >>= &= ^= |= , # ##
        fyi >>= is >> and assign
        */
		return Operator
	}

\".*\"	{
		/*
		String-LITERAL
		*/
	}



;   {
        /*
        punctuators
        [](){}*,:=;...#
        end of line, list elemnt seperators
        */
    }

.   {
    /*
    catchall case
    */
}
