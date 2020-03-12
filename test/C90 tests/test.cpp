#include <stack>
#include <vector>
int main(){
    std::stack<std::vector<int> > stk;
    stk.push(std::vector<int>());
    stk.top().push_back(2);
    return (stk.top().back());
}