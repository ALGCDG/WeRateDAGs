


typedef struct{
    int (*fpt)(int);

} testlol;

int main(){
    testlol a;
    //struct testlol* b = &a;
    //a.fpt = &f2;
    a.fpt(3);
    //b->fpt(2);
    //f3(2);
}