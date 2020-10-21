#include <iostream>

using namespace std;

void funkcja3(int &a, int *b)
{

        swap(a,*b);
}

int main()
{
    int a,b;
    cout<<"Podaj dwie liczby calkowite ";
    cin>>a>>b;
    int *wsk=&b;
    cout<<"Zmienne przed funkcja"<<endl;
    cout<<"a="<<a<<'\t'<<"b="<<b<<endl;
    funkcja3(a,wsk);
    cout<<"Zmienne po funkcji"<<endl;
    cout<<"a="<<a<<'\t'<<"b="<<b;


    return 0;
}