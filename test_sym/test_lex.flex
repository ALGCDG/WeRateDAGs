/*Testing symbol table*/
/*Code from lab - 2-regexes*/


%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "maths_parser.tab.hpp"

#include "symtab.hpp"
%}

%%

'^"typedef"'       {
                    return DECL;
                    }

[a-z]+              {
                        switch(get_sym(yytext)){
                            case "ident":
                                return STANDARD;
                            case "type":
                                return SPECIAL;
                        }
                    }

[ \t\r\n]+		{;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
