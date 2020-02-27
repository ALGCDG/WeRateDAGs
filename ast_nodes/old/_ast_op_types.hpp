#ifndef AST_OP_TYPES
#define AST_OP_TYPES

//! Not node -> move to different file
//? Use namespace instead of class?
// class BinaryOpType{

// };
namespace WRDAGS{
enum BinaryOpType{
//TODO List all binary ops possible
//?Include compound assign here?
//standard arithmetic
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
//bitwise shift
    SHL,
    SHR,
//bitwise operators
    AND,
    OR,
    XOR,
//comparison
    LT,
    GT,
    LE,
    GE,
    EQ,
    NE,
//
};

enum UnaryOpType{
//TODO List all unary ops
};

};

#endif