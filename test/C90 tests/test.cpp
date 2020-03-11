#include <cstddef>
int main(){
    int* a = NULL;
    int b = 2;
    int * c = &b;
    if(a) return 1;
    if(c) return 2;
    else return 3;
}