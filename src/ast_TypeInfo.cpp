#include "ast_TypeInfo.hpp"
#include <exception>

void TypeInfo::SetBaseSpecDetails(const std::string& singleSpec){
    if(singleSpec=="int"){
        Options = INT;
        isSigned = true;
    }
    else if(singleSpec=="double"){
        Options = DOUBLE;
    }
    else if(singleSpec=="float"){
        Options = FLOAT;
    }
    else if(singleSpec=="char"){
        Options = CHAR;
        isSigned = true;
    }
}

void TypeInfo::SetBaseSpecDetails(const std::string& specOne,const std::string& specTwo){
    bool oneIsSignSpec = (specOne == "unsigned" || specOne == "signed");
    std::string signSpec;
    std::string typeSpec;
    if(oneIsSignSpec){ signSpec = specOne; typeSpec = specTwo; }
    else{ signSpec = specTwo; typeSpec = specOne; }
    SetBaseSpecDetails(typeSpec);
    if(signSpec=="unsigned") isSigned = false;
}

TypeInfo::TypeInfo(genericConstituentType* gen){
    TypeInfo();
    bool appended = false;
    if(gen->AppendToCorrectPtr(isFunc)){
        Options = FUNC;
    }
    else if(gen->AppendToCorrectPtr(isArr)){
        Options = ARR;
    }
    else if(gen->AppendToCorrectPtr(isBaseType)){
        if(isBaseType->specs.size()==2){ SetBaseSpecDetails(isBaseType->specs[0], isBaseType->specs[1]);}
        else if(isBaseType->specs.size()==1){ SetBaseSpecDetails(isBaseType->specs[0]); }
        else { throw std::runtime_error("More than three type specs!"); }
    }
    else if(gen->AppendToCorrectPtr(isStruct)){
        Options = STRUCT;
    }
    else if(gen->AppendToCorrectPtr(isEnum)){
        Options = ENUM;
    }
    else if(gen->AppendToCorrectPtr(isPt)){
        Options = POINTER;
        pointerDataSize = isPt->ByteSize();
    }
}

TypeInfo* TypeGetter::GetType(Expression* _Expression){}
TypeInfo* TypeGetter::GetType(IdentifierNode* _IdentifierNode){
    genericConstituentType* gen = _IdentifierNode->ContextRecord->GetPrimary();
    TypeInfo* info = new TypeInfo(gen);
    return info;
}
TypeInfo* TypeGetter::GetType(Constant* _Constant){}
TypeInfo* TypeGetter::GetType(constant_int* _constant_int){
    TypeInfo* info = new TypeInfo;
    info->Options=TypeInfo::INT;
}
TypeInfo* TypeGetter::GetType(constant_char* _constant_char){
    TypeInfo* info = new TypeInfo;
    info->Options=TypeInfo::CHAR;
}
TypeInfo* TypeGetter::GetType(StringLiteral* _StringLiteral){
    TypeInfo* info = new TypeInfo;
    //todo
    return info;
}
TypeInfo* TypeGetter::GetType(TypedefNode* _TypedefNode){}
TypeInfo* TypeGetter::GetType(PostfixExpr* _PostfixExpr){}
TypeInfo* TypeGetter::GetType(ArgExprList* _ArgExprList){}
TypeInfo* TypeGetter::GetType(ArraySubscript* _ArraySubscript){
    TypeInfo* below = _ArraySubscript->LHS->acceptTypeGetter(this);
    arrayType* arr = below->isArr;
    TypeInfo* returnInfo;
    if(arr->nextArray!=NULL){ returnInfo = new TypeInfo(arr->nextArray);}
    else if(arr->pointerElementType!=NULL){ returnInfo = new TypeInfo(arr->pointerElementType);}
    else if(arr->basetypeElementType!=NULL){ returnInfo = new TypeInfo(arr->basetypeElementType);}
    else{ throw std::string("No non null array type part"); }
    return returnInfo;
}
TypeInfo* TypeGetter::GetType(FuncCall* _FuncCall){
    return _FuncCall->LHS->acceptTypeGetter(this);
}
TypeInfo* TypeGetter::GetType(MemberAccess* _MemberAccess){
    return _MemberAccess->ID->acceptTypeGetter(this);
}//todo
TypeInfo* TypeGetter::GetType(DerefMemberAccess* _DerefMemberAccess){
    return _DerefMemberAccess->ID->acceptTypeGetter(this);
}//todo
//also need to call the above at the processor stage, in order to get info of lhs

TypeInfo* TypeGetter::GetType(PostInc* _PostInc){
    return _PostInc->LHS->acceptTypeGetter(this);
}
TypeInfo* TypeGetter::GetType(PostDec* _PostDec){
    return _PostDec->LHS->acceptTypeGetter(this);
}
TypeInfo* TypeGetter::GetType(PrefixExpr* _PrefixExpr){}
TypeInfo* TypeGetter::GetType(UnaryAddressOperator* _UnaryAddressOperator){}//todo!
TypeInfo* TypeGetter::GetType(UnaryDerefOperator* _UnaryDerefOperator){}//todo!
TypeInfo* TypeGetter::GetType(UnaryPlusOperator* _UnaryPlusOperator){
    return _UnaryPlusOperator->RHS->acceptTypeGetter(this);
}
TypeInfo* TypeGetter::GetType(UnaryNegOperator* _UnaryNegOperator){
    return _UnaryNegOperator->RHS->acceptTypeGetter(this);
}
TypeInfo* TypeGetter::GetType(UnaryBitwiseNotOperator* _UnaryBitwiseNotOperator){
}
TypeInfo* TypeGetter::GetType(UnaryLogicalNotOperator* _UnaryLogicalNotOperator){}
TypeInfo* TypeGetter::GetType(PreInc* _PreInc){}
TypeInfo* TypeGetter::GetType(PreDec* _PreDec){}
TypeInfo* TypeGetter::GetType(SizeofExpr* _SizeofExpr){}
TypeInfo* TypeGetter::GetType(SizeofType* _SizeofType){}
TypeInfo* TypeGetter::GetType(CastExpr* _CastExpr){}
TypeInfo* TypeGetter::GetType(BinaryOpExpression* _BinaryOpExpression){}
TypeInfo* TypeGetter::GetType(Multiply* _Multiply){}
TypeInfo* TypeGetter::GetType(Divide* _Divide){}
TypeInfo* TypeGetter::GetType(Modulo* _Modulo){}
TypeInfo* TypeGetter::GetType(Add* _Add){}
TypeInfo* TypeGetter::GetType(Sub* _Sub){}
TypeInfo* TypeGetter::GetType(ShiftLeft* _ShiftLeft){}
TypeInfo* TypeGetter::GetType(ShiftRight* _ShiftRight){}
TypeInfo* TypeGetter::GetType(LogicalBinaryExpression* _LogicalBinaryExpression){}
TypeInfo* TypeGetter::GetType(LessThan* _LessThan){}
TypeInfo* TypeGetter::GetType(GreaterThan* _GreaterThan){}
TypeInfo* TypeGetter::GetType(LessThanOrEqual* _LessThanOrEqual){}
TypeInfo* TypeGetter::GetType(GreaterThanOrEqual* _GreaterThanOrEqual){}
TypeInfo* TypeGetter::GetType(EqualTo* _EqualTo){}
TypeInfo* TypeGetter::GetType(NotEqualTo* _NotEqualTo){}
TypeInfo* TypeGetter::GetType(LogicalAND* _LogicalAND){}
TypeInfo* TypeGetter::GetType(LogicalOR* _LogicalOR){}
TypeInfo* TypeGetter::GetType(BitwiseBinaryExpression* _BitwiseBinaryExpression){}
TypeInfo* TypeGetter::GetType(BitwiseAND* _BitwiseAND){}
TypeInfo* TypeGetter::GetType(BitwiseOR* _BitwiseOR){}
TypeInfo* TypeGetter::GetType(BitwiseXOR* _BitwiseXOR){}
TypeInfo* TypeGetter::GetType(TernaryOpExpression* _TernaryOpExpression){}
TypeInfo* TypeGetter::GetType(GenericAssignExpr* _GenericAssignExpr){}
TypeInfo* TypeGetter::GetType(AssignmentExpression* _AssignmentExpression){}
TypeInfo* TypeGetter::GetType(MulAssignment* _MulAssignment){}
TypeInfo* TypeGetter::GetType(DivAssignment* _DivAssignment){}
TypeInfo* TypeGetter::GetType(ModAssignment* _ModAssignment){}
TypeInfo* TypeGetter::GetType(AddAssignment* _AddAssignment){}
TypeInfo* TypeGetter::GetType(SubAssignment* _SubAssignment){}
TypeInfo* TypeGetter::GetType(ShiftLeftAssignment* _ShiftLeftAssignment){}
TypeInfo* TypeGetter::GetType(ShiftRightAssignment* _ShiftRightAssignment){}
TypeInfo* TypeGetter::GetType(BitwiseANDAssignment* _BitwiseANDAssignment){}
TypeInfo* TypeGetter::GetType(BitwiseXORAssignment* _BitwiseXORAssignment){}
TypeInfo* TypeGetter::GetType(BitwiseORAssignment* _BitwiseORAssignment){}
TypeInfo* TypeGetter::GetType(ConstantExpression* _ConstantExpression){}
TypeInfo* TypeGetter::GetType(CommaSepExpression* _CommaSepExpression){}