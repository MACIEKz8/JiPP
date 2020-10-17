#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    int mac1[2][3],mac2[2][3], wynik[2][3];

    srand(time(NULL));

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            mac1[i][j]=rand()%100;
            mac2[i][j]=rand()%100;
        }
    }
    cout <<"MACIERZ1:"<<endl;
      for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<"mac["<<i<<"]["<<j<<"] = "<<mac1[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<endl<<"                     +"<<endl;
    cout <<endl<<"MACIERZ2:"<<endl;
      for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<"mac["<<i<<"]["<<j<<"] = "<<mac2[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<"_______________________________________________"<<endl<<endl;
    cout<<"MACIERZ WYNIKOWA"<<endl;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            wynik[i][j]=mac1[i][j]+mac2[i][j];
            cout<<"mac["<<i<<"]["<<j<<"] = "<<wynik[i][j]<<"\t";
        }
        cout<<endl;
    }
    getchar();
    return 0;

}