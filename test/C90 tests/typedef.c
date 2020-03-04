int f(){
    int b = 1;
    void g(){
        b+=1;
    }
    g();
    return b;
}

int main()
{
    return f();
}
