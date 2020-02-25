int f1(int a){
    return a*2;
}

int x = 3;

int f2(int b){
    return f1(b);
}

int main(){
    int test = 2;
    return (test == test) ?f2(test) : f1(x) ;

}