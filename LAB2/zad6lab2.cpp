#include <iostream>

using namespace std;

void my_swap(string &a, string &b)
{
    string c;
    c=a;
    a=b;
    b=c;
}

int main()
{
    string a,b;
    cout<<"Podaj dwie zmienne: ";
    cin>>a>>b;
    cout<<"Zmienne przed funkcja"<<endl;
    cout<<"1: "<<a<<'\t'<<"2: "<<b<<endl;
    my_swap(a,b);
    cout<<"Zmienne po funkcji"<<endl;
    cout<<"1: "<<a<<'\t'<<"2: "<<b;
    return 0;
}