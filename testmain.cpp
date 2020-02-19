#include"tokens.hpp"
#include<iostream>
TokenValue yylval;
int main()
{
    while(1)
    {
        TokenType t = (TokenType)yylex();
        if(t==None)
        {
            break;
        }
        std::cout << *yylval.text << std::endl;
        delete yylval.text;
    }
    return 0;
}
