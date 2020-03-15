#include <stack>
#include <vector>
#include <iostream>

//double dispatch example of appending

class B;
class C;
class A{
    public:
    int a;
    virtual void beAppended(A* a) = 0;
    virtual void append(B* b) = 0;
    virtual void append(C* c) = 0;
};

class B : public A{
public:
    void append(B* b){ std::cout << "B append B" << std::endl; }
    void append(C* c){ std::cout << "B append C"<< std::endl; }
    void beAppended(A* a){ a->append(this); }
};

class C : public A{
public:
    void append(B* b) { std::cout << "C append B"<< std::endl; }
    void append(C* c) override { std::cout << "C append C"<< std::endl; }
    void beAppended(A* a) override { a->append(this); }
};


int main(){
    C * a = new C;
    C * b = new C;
    B * c = new B;
    B * d = new B;
    std::vector<A*> vec = {a,b,c,d};
    for (int i = vec.size()-1; i > 0; i--){
        vec[i]->beAppended(vec[i-1]);
    }
}