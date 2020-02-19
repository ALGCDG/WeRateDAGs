%option noyywrap

%{
#include "tokens.hpp"
#include <iostream>
#include <sstream>
extern "C" int fileno(FILE *stream); // fixing bug in flex
%}

Sign [+-]
Exponent [eE]
Decimal [0-9]
NonZero [1-9]
Float [fF]
Long [lL]

A [a-zA-Z_]
P [a-zA-Z_0-9]

X [xX]
Hex [a-fA-F0-9]

Octal [0-7]

B [bB]
Binary [01]

Operator [+\-*/%&|^><=!~?:.,#\[\]\(\)\{\}]

%%
"int"   {
            /*
            Keywords
            type data: int char etc... but also unsigned, struct, enum
            structures: if, else, for, while, do, return, break continue case
            builtin functions: sizeof
            luckily not flexible
            */
            fprintf(stderr, "its a keyword");
            return Keyword_int;
}

{A}{P}* {
            /*
            Identifier
            variable names, function names, etc...
            */
            fprintf(stderr, "its an identifier");      
            yylval.text = new std::string(yytext);
            return Identifier;
}

{Sign}?{Decimal}*\.{Decimal}*({Exponent}{Sign}?{Decimal}+)?   {
        /*
        double constant
        */
        fprintf(stderr, "its a double constant");
		return Constant;
}

{Sign}?{Decimal}*\.{Decimal}*({Exponent}{Sign}?{Decimal}+)?{Float}   {
        /*
        float constant
        */
        fprintf(stderr, "its a float constant");
		return Constant;
}

{Sign}?{Decimal}*\.{Decimal}*({Exponent}{Sign}?{Decimal}+)?{Long}   {
        /*
        long double constant
        */
        fprintf(stderr, "its a long double constant");
		return Constant;
}


{Sign}?{NonZero}{Decimal}*   {
        /*
        decimal constant
        */
        fprintf(stderr, "its a decimal constant: %s\n", yytext);
        yylval.ivalue = std::stoi(yytext);
		return Constant_int;
	}

0{X}{Hex}+   {
                    /*
                    hexadecimal constant
                    */
                    std::stringstream s;
                    s << std::hex << yytext;
                    s >> yylval.ivalue;
                    fprintf(stderr, "its a hex constant: %d\n", yylval.ivalue);
		            return Constant_int;
}

0{B}{Binary}+   {
                    /*
                    binary constant
                    */
                    yylval.ivalue = 0;
                    for (int i = 2; i < yyleng; i++)
                    {
                        yylval.ivalue += (yytext[i] == '1') << (yyleng - i - 1); 
                    }       
                    fprintf(stderr, "its a binary constant: %d\n", yylval.ivalue);
    	            return Constant_int;
}

0{Octal}*   {
                /*
                octal constant
                */
                std::stringstream s;
                s << std::oct << yytext;
                s >> yylval.ivalue;
                fprintf(stderr, "its an octal constant: %s\n", yylval.ivalue);
    	        return Constant_int;
}

\'.\'	{
		/*
		Char
        also returns a constant
		*/
        yylval.cvalue = yytext[1];
        fprintf(stderr, "its a char constant: %s\n", yylval.cvalue);
        return Constant;
}

{Operator}|"sizeof "|"=="|"!="|"<="|">="|"+="|"-="|"*="|"/="|"%="|"&="|"|="|"^="|"<<="|">>="|"##"|"++"|"--"|"<<"|">>"	{
        /*
        Operator
        [ ] ( ) . -> ++ -- & * + - ~ ! i sizeof / % << >> < > <= >= == != ^ | && || ? : = *= /= %= += -= <<= >>= &= ^= |= , # ##
        fyi >>= is >> and assign
        */
        fprintf(stderr, "its an operator: %s/n", yytext);
        yylval.text = new std::string(yytext);
        return Operator;
}

"+" { return Operator_add; }
"-" { return Operator_sub; }
"++" { return Operator_addadd; }
"--" { return Operator_subsub; }
"*" { return Operator_mul; OR return Operator_deref; }
"/" { return Operator_div; }
"%" { return Operator_mod; }
"&&" { return Operator_and; }
"||" { return Operator_or; }
"!" { return Operator_not; }
"=" { return Operator_assign; }
"==" { return Operator_equal; }
"!=" { return Operator_not_equal; }
">" { return Operator_greater; }
"<" { return Operator_less; }
">=" { return Operator_greater_equal; }
"<=" { return Operator_less_equal; }
"&" { return Operator_bit_and; OR return Operator_ref; }
"|" { return Operator_bit_or; }
"~" { return Operator_bit_not; }
"^" { return Operator_bit_xor; }
"<<" { return Operator_sl; }
">>" { return Operator_sr; }
"+=" { return Operator_add_assign; }
"-=" { return Operator_sub_assign; }
"*=" { return Operator_mul_assign; }
"/=" { return Operator_div_assign; }
"%=" { return Operator_mod_assign; }
"&=" { return Operator_and_assign; }
"|=" { return Operator_or_assign; }
"^=" { return Operator_xor_assign; }
">>=" { return Operator_sr_assign; }
"<<=" { return Operator_sl_assign; }
"." { return Operator_access; }
"->" { return Operator_deref_access; }
"sizeof " { return Operator_sizeof; }

\".[^"]*\"	{
        /*
        String-LITERAL
        */
        std::string match = std::string(yytext);
        yylval.text = new std::string();
        *(yylval.text) = match.substr(1, yyleng - 2);
        fprintf(stderr, "its a string literal: %s\n", *(yylval.text)); 
        return String;
}



;   {
        /*
        punctuators
        [](){}*,:=;...#
        end of line, list elemnt seperators
        */
        fprintf(stderr, "its a punctuator");
        return Punctuator;
}

.   {
        /*
        catchall case
        */
}
