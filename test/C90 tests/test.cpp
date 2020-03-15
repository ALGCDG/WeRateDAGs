#include <stack>
#include <vector>
#include <iostream>

class A{
    int a;
    virtual void f() = 0;
};

class B : public A{
    int b;
    void f(){}
};

void func(A*){
    std::cout << 0;
}

void func(B*){
    std::cout << 1;
}
int main(){
    A *a, *b;
    B *c, *d;
    std::vector<A*> vec = {a,b,c,d};
    for (auto i: vec){
        func(i);
    }
}