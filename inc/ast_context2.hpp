#include <vector>
#include <string>

struct genericConstituentType{
    virtual void AddNextType(genericConstituentType* nexttype){}
    virtual void AddNextType(typeSpecifiers* specs){}
    virtual void AddNextType(typeSpecifiers* typ){}
    virtual void AddNextType(functionType* func){}
    virtual void AddNextType(arrayType* arr){}
    virtual void AddNextType(pointerType* point){}
};

struct functionType : public genericConstituentType{
    void AddNextType(typeSpecifiers* specs) override;
    void AddNextType(pointerType* point) override;
    typeSpecifiers* basetypeReturnType;
    pointerType* pointerReturnType;
    funcArgs* arguments;
};

struct arrayType : public genericConstituentType{
    arrayType(int _size) : size(_size){}
    int size;
    void AddNextType(arrayType* arr) override;
    void AddNextType(pointerType* pnt) override;
    void AddNextType(typeSpecifiers* typ) override;

    arrayType* nextArray;
    pointerType* pointerElementType;
    typeSpecifiers* basetypeElementType;
};

struct pointerType : public genericConstituentType{
    void AddNextType(arrayType* arr) override;
    void AddNextType(pointerType* pnt) override;
    void AddNextType(typeSpecifiers* typ) override;
    pointerType* ptToPointer;
    arrayType* ptToArray;
    typeSpecifiers* ptToBasetype;
    functionType* ptToFunc;
};

struct typeSpecifiers : public genericConstituentType{
    typeSpecifiers* otherSpecs;
    void AddNextType(typeSpecifiers* specs);
};

struct funcArgs{
    //abstract represented with empty string
    std::vector<std::pair<std::string, genericConstituentType*> > args;
};

