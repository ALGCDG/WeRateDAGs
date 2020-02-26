


typedef struct{
    int (*fpt)(int);

} testlol;

int main(){
    struct{
    int (*fpt)(int);
    } a;
    //struct testlol* b = &a;
    //a.fpt = &f2;
    a.fpt(3);
    //test2
    //b->fpt(2);
    //f3(2);
}