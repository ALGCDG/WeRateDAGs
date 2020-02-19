%option noyywrap

%{
#include "tokens.hpp"
extern "C" int fileno(FILE *stream); // fixing bug in flex
%}

Sign [+-]
Exponent [eE]
Decimal [0-9]
NonZero [1-9]

A [a-zA-Z_]
P [a-zA-Z_0-9]

X [xX]
Hex [a-fA-F0-9]

Octal [0-7]

B [bB]
Binary [01]

Operator [+\-*/%&|^><=!~?:.,#\[\]\(\)\{\}]

%%
"int"|"float"   {
        /*
        Keywords
        type data: int char etc... but also unsigned, struct, enum
        structures: if, else, for, while, do, return, break continue case
        builtin functions: sizeof
        luckily not flexible
        */
        fprintf(stderr, "its a keyword");
		//return KEYWORD(INT);
	}

{A}{P}*	{
        fprintf(stderr, "its an identifier");      
		//return IDENTIFIER;
	}

{Sign}?{Decimal}*\.{Decimal}*({Exponent}{Sign}?{Decimal}+)?   {
        // decimal numbers
        fprintf(stderr, "its a float constant");
		//return CONSTANT;
	}

{Sign}?{NonZero}{Decimal}*   {
        // decimal numbers
        fprintf(stderr, "its a decimal constant");
		//return CONSTANT;
	}

0{X}{Hex}+   {
        // hex number
        fprintf(stderr, "its a hex constant");
		//return CONSTANT;
	}

0{B}{Binary}+   {
        fprintf(stderr, "its a binary constant");
    }

0{Octal}*   {
                fprintf(stderr, "its an octal constant");
            }

\'.\'	{
		/*
		Char
        also returns a constant
		*/
        fprintf(stderr, "its a char constant");
        //return CONSTANT;
	}

{Operator}|"sizeof "|"=="|"!="|"<="|">="|"+="|"-="|"*="|"/="|"%="|"&="|"|="|"^="|"<<="|">>="|"##"|"++"|"--"|"<<"|">>"	{
        /*
        Operator
        [ ] ( ) . -> ++ -- & * + - ~ ! i sizeof / % << >> < > <= >= == != ^ | && || ? : = *= /= %= += -= <<= >>= &= ^= |= , # ##
        fyi >>= is >> and assign
        */
        fprintf(stderr, "its an operator");
		//return Operator
	}

\".[^"]*\"	{
		/*
		String-LITERAL
		*/
        fprintf(stderr, "its a string literal");
	}



;   {
        /*
        punctuators
        [](){}*,:=;...#
        end of line, list elemnt seperators
        */
        fprintf(stderr, "its a punctuator");

    }

.   {
    /*
    catchall case
    */
}
