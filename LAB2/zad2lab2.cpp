#include <iostream>

using namespace std;

void funkcja2(int &a, int &b)
{
        swap(a,b);
}

int main()
{
    int a,b;
    cout<<"Podaj dwie liczby calkowite ";
    cin>>a>>b;
    cout<<"Zmienne przed funkcja"<<endl;
    cout<<"a="<<a<<'\t'<<"b="<<b<<endl;
    funkcja2(a,b);
    cout<<"Zmienne po funkcji"<<endl;
    cout<<"a="<<a<<'\t'<<"b="<<b;


    return 0;
}