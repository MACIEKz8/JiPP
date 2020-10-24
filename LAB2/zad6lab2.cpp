#include <iostream>

using namespace std;
template <typename T>

void my_swap(T **a, T **b)
{
    T *c = *a;
    *a = *b;
    *b = c;
}

int main()
{
    string a,b;
    cout<<"Podaj dwie zmienne: ";
    cin>>a>>b;
    string *wsk1, *wsk2;
    wsk1 = &a;
    wsk2 = &b;
    cout<<"Zmienne przed funkcja:"<<endl;
    cout<<"1: "<<*wsk1<<'\t'<<"2: "<<*wsk2<<endl;
    my_swap(&wsk1,&wsk2);
    cout<<"Zmienne po funkcji:"<<endl;
    cout<<"1: "<<*wsk1<<'\t'<<"2: "<<*wsk2;
    return 0;
}