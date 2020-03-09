#include "compiler.hpp"
#include "ast_allnodes.hpp"
#include "visitors.hpp"
#include "py_translate_vis.hpp"
int main(int argc, char** argv)
{
	// creating ast
    Node *ast=parseAST();

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
	
	// creating visitor
	Visitor* language_processor = translate_flag ? new python_Visitor() : new Visitor() ;
	// visiting ast
    ast->accept(language_processor);
    return 0;
}