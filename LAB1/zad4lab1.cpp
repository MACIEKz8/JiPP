#include <iostream>

using namespace std;

int main()
{
    int a,b,suma_a=0,suma_b=0;

    cout<<"Podaj pierwsza liczbe: ";
    cin>>a;
    cout<<"Podaj druga liczbe: ";
    cin>>b;

    for (int i=1;i<a;i++)
    {
        if(a%i==0)
            suma_a+=i;
    }

    for (int i=1;i<b;i++)
    {
        if(b%i==0)
            suma_b+=i;
    }

    if(suma_a==b+1 && suma_b==a+1)
        cout<<"Podane liczby sa liczbami skojarzonymi";
    else
        cout<<"Podane liczby nie sa liczbami skojarzonymi";
    
    getchar();
    return 0;
}