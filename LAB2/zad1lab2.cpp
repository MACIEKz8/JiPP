#include <iostream>

using namespace std;

void funkcja1(int *a, int *b)
{
    if (*a>*b)
        swap(*a,*b);
}

int main()
{
    int *wsk1, *wsk2;
    int a,b;
    cout<<"Podaj dwie zmienne: ";
    cin>>a>>b;
    wsk1=&a;
    wsk2=&b;
    cout<<"Zmienne przed funkcja"<<endl;
    cout<<"a="<<a<<'\t'<<"b="<<b<<endl;
    funkcja1(wsk1,wsk2);
    cout<<"Zmienne po funkcji"<<endl;
    cout<<"a="<<a<<'\t'<<"b="<<b;
    return 0;
}