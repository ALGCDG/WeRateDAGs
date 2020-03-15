#include <stack>
#include <vector>
#include <iostream>

class A{
    public:
    int a;
    virtual A* f() = 0;
};

class B : public A{
    public:
    int b;
    B* f() override{ return this; }
};

class C : public A{
public:
    C* f() override { return this; }
};

void func(A*){
    std::cout << -1;
}
void func(C*){
    std::cout << 0;
}

void func(B*){
    std::cout << 1;
}
int main(){
    A * a = new C;
    A * b = new C;
    B * c = new B;
    B * d = new B;
    std::vector<A*> vec = {a,b,c,d};
    for (auto i: vec){
        func(i->f());
    }
}