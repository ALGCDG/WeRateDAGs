#include "ast_allnodes.hpp"
#include <iostream>
#include <queue>
#include <regex>

/*static*/
PrefixExpr* PrefixExpr::DecodeUnaryOp(std::string* yytext, Expression* _RHS){
    std::string op = *yytext;
    if(op == "*") return new UnaryDerefOperator(_RHS);
    else if(op == "&") return new UnaryAddressOperator(_RHS);
    else if(op == "+") return new UnaryPlusOperator(_RHS);  
    else if(op == "-") return new UnaryNegOperator(_RHS);
    else if(op == "~") return new UnaryBitwiseNotOperator(_RHS);
    else if(op == "!") return new UnaryLogicalNotOperator(_RHS);
    else return NULL;
    
}/*static*/
GenericAssignExpr* GenericAssignExpr::DecodeAssignOp(Expression* LHS, std::string* yytext, Expression* RHS)
{
    std::cerr << "decoding assignment" << std::endl;
    std::string op = *yytext;
    if(op == "="){
        std::cerr << "new = sign" << std::endl;
        return new AssignmentExpression(LHS,RHS);
    }
    else if(op == "*=") return new MulAssignment(LHS, RHS);
    else if(op == "/=") return new DivAssignment(LHS,RHS);
    else if(op == "%=") return new ModAssignment(LHS,RHS);
    else if(op == "+=") return new AddAssignment(LHS,RHS);
    else if(op == "-=") return new SubAssignment(LHS,RHS);
    else if(op == "<<=") return new ShiftLeftAssignment(LHS,RHS);
    else if(op == ">>=") return new ShiftRightAssignment(LHS,RHS);
    else if(op == "&=") return new BitwiseANDAssignment(LHS,RHS);
    else if(op == "^=") return new BitwiseXORAssignment(LHS,RHS);
    else if(op == "|=") return new BitwiseORAssignment(LHS,RHS);
    else return NULL;
}


unsigned char evalOctCode(std::string code){
	unsigned char count = 0;
	for(int i = 0; i < code.length();i++){
		count += (code[i]-'0')*std::pow(8,code.length()-i-1);
	}
	return count;
}

unsigned char evalHexCode(std::string code){
	unsigned char count = 0;
	for(int i = 0; i < code.length(); i++){
		if(code[i] >= 'a') code[i] = code[i] - 32;
		count += ((code[i] >= 'A') ? (code[i] - 'A' + 10) : (code[i] - '0'))*std::pow(16,code.length()-i-1);
	}
	return count;
}
std::string ConvertEscapes(const std::string& str_in){
    static const std::regex simpleEsc(R"((\\'|\\"|\\\?|\\\\|\\a|\\b|\\f|\\n|\\r|\\t|\\v))");
    static const std::regex octalEsc(R"(\\[0-7]{1,3})");
    static const std::regex hexEsc(R"(\\x[0-9a-fA-F]+)");
    
    std::string str_out;
    std::string buffer;
    bool expect_oct = false;
    bool expect_hex = false;
    for(auto next_char : str_in){
        if(buffer.length()==0){
            if(next_char=='\\'){ buffer+=next_char; }
            else { str_out+=next_char; }
        }
        else{
            buffer+=next_char;
            if(std::regex_match(buffer,simpleEsc)){
                switch(buffer[1]){
                    case '\'':
                        str_out+='\'';
                        buffer = "";
                    case '\"':
                        str_out+='\"';
                        buffer = "";
                    case '\?':
                        str_out+='\?';
                        buffer = "";
                    case '\\':
                        str_out+='\\';
                        buffer = "";
                    case 'a':
                        str_out+='\a';
                        buffer = "";
                    case 'b':
                        str_out+='\b';
                        buffer = "";
                    case 'f':
                        str_out+='\f';
                        buffer = "";
                    case 'n':
                        str_out+='\n';
                        buffer = "";
                    case 'r':
                        str_out+='\r';
                        buffer = "";
                    case 't':
                        str_out+='\t';
                        buffer = "";
                    case 'v':
                        str_out+='\v';
                        buffer = "";
                }
            }
            else if(buffer.length()==2){
                if(buffer[1]=='x') expect_hex = true;
                else if(std::regex_match(buffer, octalEsc)) expect_oct = true;
            }
            else if(expect_hex){
                //length at least 3 now
                if(!std::regex_match(buffer,hexEsc)){
                    str_out+=evalHexCode(buffer.substr(0,buffer.length()-1));
                    if(buffer.back() == '\\' ){
                        buffer = buffer.back();
                    }
                    else{
                        str_out += buffer.back();
                        buffer = "";
                    }
                    expect_hex = false;
                }
            }
            else if(expect_oct){
                if(!std::regex_match(buffer,octalEsc)){
                    str_out+=evalOctCode(buffer.substr(0,buffer.length()-1));
                    if(buffer.back() == '\\'){
                        buffer = buffer.back();
                    }
                    else{
                        str_out+=buffer.back();
                        buffer = "";
                    }
                    expect_oct = false;
                }
            }            
        }
    }
    if(buffer.length()!=0){
        if(std::regex_match(buffer,octalEsc)){ str_out += evalOctCode(buffer);}
        else if(std::regex_match(buffer, hexEsc)){ str_out += evalHexCode(buffer);}
        else{ str_out += buffer;}
    }
        return str_out;
}