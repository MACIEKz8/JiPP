#include <iostream>

using namespace std;

int funkcja4(int &a, int &b)
{
    b=b+a;
    return a*(b-a);
}

int main()
{
    int a,b;
    cout<<"Podaj dwie liczby calkowite: ";
    cin>>a>>b;
    cout<<"Iloczyn: "<<funkcja4(a,b)<<endl;
    cout<<"Suma: "<<b;


    return 0;
}