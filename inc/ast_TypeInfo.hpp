#ifndef AST_TYPE_HPP
#define AST_TYPE_HPP

#include "ast_allnodes.hpp"
#include "ast_context2.hpp"

struct TypeInfo{
    TypeInfo():isFunc(NULL),isArr(NULL),isPt(NULL),isBaseType(NULL),isStruct(NULL),isEnum(NULL){}
    TypeInfo(genericConstituentType* gen);
    enum type_ops{INT,FLOAT,CHAR,POINTER,STRUCT,DOUBLE,FUNC,ARR,ENUM} Options;
    std::experimental::optional<unsigned int> pointerDataSize;
    std::experimental::optional<bool> isSigned;
    functionType* isFunc;
    arrayType* isArr;
    pointerType* isPt;
    typeSpecifiers* isBaseType;
    structType* isStruct;
    enumType* isEnum;
    // static bool IntegralPromoteIsSigned(TypeInfo* A);
    static TypeInfo* UsualArithConversion(TypeInfo* A, TypeInfo* B);
private:
    void SetBaseSpecDetails(const std::string& singleSpec);
    void SetBaseSpecDetails(const std::string& specOne,const std::string& specTwo);
};

class TypeGetter : public AbstractTypeGetter{    
public:
    TypeInfo* GetType(Expression* _Expression);
    TypeInfo* GetType(IdentifierNode* _IdentifierNode);
    TypeInfo* GetType(Constant* _Constant);
    TypeInfo* GetType(constant_int* _constant_int);
    TypeInfo* GetType(constant_char* _constant_char);
    TypeInfo* GetType(constant_float* _constant_float);
    TypeInfo* GetType(StringLiteral* _StringLiteral);
    TypeInfo* GetType(TypedefNode* _TypedefNode);
    TypeInfo* GetType(PostfixExpr* _PostfixExpr);
    TypeInfo* GetType(ArgExprList* _ArgExprList);
    TypeInfo* GetType(ArraySubscript* _ArraySubscript);
    TypeInfo* GetType(FuncCall* _FuncCall);
    TypeInfo* GetType(MemberAccess* _MemberAccess);
    TypeInfo* GetType(DerefMemberAccess* _DerefMemberAccess);
    TypeInfo* GetType(PostInc* _PostInc);
    TypeInfo* GetType(PostDec* _PostDec);
    TypeInfo* GetType(PrefixExpr* _PrefixExpr);
    TypeInfo* GetType(UnaryAddressOperator* _UnaryAddressOperator);
    TypeInfo* GetType(UnaryDerefOperator* _UnaryDerefOperator);
    TypeInfo* GetType(UnaryPlusOperator* _UnaryPlusOperator);
    TypeInfo* GetType(UnaryNegOperator* _UnaryNegOperator);
    TypeInfo* GetType(UnaryBitwiseNotOperator* _UnaryBitwiseNotOperator);
    TypeInfo* GetType(UnaryLogicalNotOperator* _UnaryLogicalNotOperator);
    TypeInfo* GetType(PreInc* _PreInc);
    TypeInfo* GetType(PreDec* _PreDec);
    TypeInfo* GetType(SizeofExpr* _SizeofExpr);
    TypeInfo* GetType(SizeofType* _SizeofType);
    TypeInfo* GetType(CastExpr* _CastExpr);
    TypeInfo* GetType(BinaryOpExpression* _BinaryOpExpression);
    TypeInfo* GetType(Multiply* _Multiply);
    TypeInfo* GetType(Divide* _Divide);
    TypeInfo* GetType(Modulo* _Modulo);
    TypeInfo* GetType(Add* _Add);
    TypeInfo* GetType(Sub* _Sub);
    TypeInfo* GetType(ShiftLeft* _ShiftLeft);
    TypeInfo* GetType(ShiftRight* _ShiftRight);
    TypeInfo* GetType(LogicalBinaryExpression* _LogicalBinaryExpression);
    /*TypeInfo* GetType(LessThan* _LessThan);
    TypeInfo* GetType(GreaterThan* _GreaterThan);
    TypeInfo* GetType(LessThanOrEqual* _LessThanOrEqual);
    TypeInfo* GetType(GreaterThanOrEqual* _GreaterThanOrEqual);
    TypeInfo* GetType(EqualTo* _EqualTo);
    TypeInfo* GetType(NotEqualTo* _NotEqualTo);
    TypeInfo* GetType(LogicalAND* _LogicalAND);
    TypeInfo* GetType(LogicalOR* _LogicalOR);*/
    TypeInfo* GetType(BitwiseBinaryExpression* _BitwiseBinaryExpression);
    /*TypeInfo* GetType(BitwiseAND* _BitwiseAND);
    TypeInfo* GetType(BitwiseOR* _BitwiseOR);
    TypeInfo* GetType(BitwiseXOR* _BitwiseXOR);*/
    TypeInfo* GetType(TernaryOpExpression* _TernaryOpExpression);
    TypeInfo* GetType(GenericAssignExpr* _GenericAssignExpr);
    /*TypeInfo* GetType(AssignmentExpression* _AssignmentExpression);
    TypeInfo* GetType(MulAssignment* _MulAssignment);
    TypeInfo* GetType(DivAssignment* _DivAssignment);
    TypeInfo* GetType(ModAssignment* _ModAssignment);
    TypeInfo* GetType(AddAssignment* _AddAssignment);
    TypeInfo* GetType(SubAssignment* _SubAssignment);
    TypeInfo* GetType(ShiftLeftAssignment* _ShiftLeftAssignment);
    TypeInfo* GetType(ShiftRightAssignment* _ShiftRightAssignment);
    TypeInfo* GetType(BitwiseANDAssignment* _BitwiseANDAssignment);
    TypeInfo* GetType(BitwiseXORAssignment* _BitwiseXORAssignment);
    TypeInfo* GetType(BitwiseORAssignment* _BitwiseORAssignment);*/
    TypeInfo* GetType(ConstantExpression* _ConstantExpression);
    // TypeInfo* GetType(CommaSepExpression* _CommaSepExpression);
    TypeInfo* GetType(Node* n);
};

#endif