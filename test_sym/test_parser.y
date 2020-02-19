/*Testing symbol table*/
/*Code from lab - 2-regexes*/
 

%code requires{
  #include "symtab.hpp"

  #include <cassert>

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  std::string *string;
}

%token STANDARD DECL SPECIAL

%type <string> STANDARD DECL SPECIAL

%start ROOT

%%


ROOT : VAR_SEQ

VAR_SEQ : STANDARD VAR_SEQ          { std::cout << "standard"; }
        | DECL STANDARD VAR_SEQ     { std::cout << "declaration of" << *$2 << " makes it special!";
                                      add_to_symtab(*$1); }
        | SPECIAL STANDARD VAR_SEQ

%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
