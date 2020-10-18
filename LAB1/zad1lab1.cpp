#include <iostream>

using namespace std;

void bubble_sort(int n, char** tab)
{
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n-1;j++)
        {
            if(atoi(tab[j]) >= atoi(tab[j+1]))
                swap(tab[j],tab[j+1]);
        }
    }

    for(int i=1;i<n;i++)
    {
        cout<<tab[i]<<" ";
    }
}

int main(int argc, char *argv[])
{
    cout<<"Wyjscie: ";
    bubble_sort(argc,argv);
    return 0;
}