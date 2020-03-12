#include "compiler.hpp"
#include "ast_allnodes.hpp"
// #include "visitors.hpp"
#include "py_translate_vis.hpp"
#include "ast_context.hpp"
#include "AST_Processor.hpp"
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
	ContextTable* Table = new ContextTable();
	ASTProcVis* astproc = new ASTProcVis(Table);
	ast->accept(astproc);

	// creating visitor
	std::cerr << "creating visitor" << std::endl;
	translate_flag=true; //TESTING translator
	Visitor* language_processor = translate_flag ? new python_Visitor() : new Visitor() ;
	// visiting ast
    ast->accept(language_processor);
	delete language_processor;
    return 0;
}