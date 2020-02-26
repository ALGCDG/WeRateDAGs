#ifndef AST_TYPES
#define AST_TYPES

#include <string>
#include <vector>


class Type{
public:
    virtual int getSize() = 0;
private:
    
};

class BasicType : public Type{
public:
    int getSize();
    enum _primary_types{
        VOID,
        INT,
        CHAR,
        DOUBLE,
        FLOAT
    };
    enum _sign_spec{
        SGN,
        USGN,
        None
    };

    enum _length_spec{
        SHORT,
        LONG,
        NONE
    };
private:
    _primary_types WhichBasicType;
    _sign_spec WhichSign;
    _length_spec WhichLength;
};

class PointerType : public Type{
private:
    Type* RefType;
};

class FuncType : public Type{
private:
    Type* RetType;
    int NumArgs;
    std::vector<Type*> Args;
};

class CustomUserType : public Type{
private:
    Identifier
    Type* CanonicalType;
};
//TODO:
//need enum type
//union
//struct
//array
//tag

#endif