#ifndef AST_TYPE
#define AST_TYPE

class Type : public Node{

};

//---------------------------

class Void : public Type{

};

class Int : public Type{

};

class Char : public Type{

};

class Double : public Type{

};

class Float : public Type{

};

class UserDefinedType : public Type{

};

//---------------------------
//structs are difficult: TODO!
class TaggedStructType : public Type{
//fields accessible inside instances of struct
};

class StructFieldType : public Type{

};


//---------------------------

class IncompleteArrayType : public Type{
//no size specified
};

class ArrayType : public Type{
//size specified
};

//---------------------------

class FunctionType : public Type{
//return type
};

//---------------------------

class PointerType : public Type{
//pointer to a type
};


#endif