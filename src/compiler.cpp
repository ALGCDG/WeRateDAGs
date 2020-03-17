#include "compiler.hpp"
#include "ast_allnodes.hpp"
// #include "visitors.hpp"
#include "py_translate_vis.hpp"
#include "ast_context2.hpp"
#include "ASTProc.hpp"
#include "three_address_vis.hpp"
#include <iostream>
int main(int argc, char** argv)
{
	
		// creating ast
		TranslationUnit *ast=parseAST();
		std::cerr << "finished parsing, start compiling" << std::endl;
		// checking if we are translating
		auto output_filename = "a.out";
		auto translate_flag = false;
		for (int i = 0; i < argc; i++)
		{
			if (std::string(argv[i]) == "-o")
			{
				i++;
				output_filename = argv[i];
			}
			if (std::string(argv[i]) == "--translate")
			{
				translate_flag = true;
			}
		}
		//processing ast
		SymbolTable* Table = new SymbolTable();
		ASTProcVis* astproc = new ASTProcVis(Table);
		try{
			astproc->ProcessAST(ast);
			Table->PrettyPrint();
		}catch(const char* e){ std::cout << e; }
		// creating visitor
		std::cerr << "creating visitor" << std::endl;
		// translate_flag=true; //TESTING translator
		// Visitor* language_processor = translate_flag ? new python_Visitor() : new three_address_Visitor() ;
		Visitor *language_processor;
		if (translate_flag)	language_processor=new python_Visitor();
		else language_processor = new three_address_Visitor();
		// visiting ast
		ast->accept(language_processor);
		delete language_processor;
		return 0;
	
}