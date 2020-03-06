#include "compiler.hpp"

int main(int argc, char** argv)
{
	// creating ast
    const Node *ast=parseAST();

	// checking if we are translating
	auto output_filename = "a.out";
	auto translate_flag = false;
	for (int i = 0; i < argc; i++)
	{
		if (argv[i] == "-o")
		{
			i++;
			output_filename = argv[i];
		}
		if (argv[i] == "--translate")
		{
			translate_flag = true;
		}
	}
	
	// creating visitor
	Visitor language_processor = translate_flag ? python_Visitor() : Visitor() ;
	// visiting ast
    ast->accept(language_processor);
    return 0;
}