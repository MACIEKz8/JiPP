#include <iostream>
#include "lab3.1.hpp"
using namespace std;


int main()
{
    macierz macierz1(5,6);
    cout<<"Macierz 5x6 bez przypisanych wartosci:"<<endl;
    macierz1.print();
    macierz macierz2(5);
    cout<<"Macierz 5x5 bez przypisanych wartosci:"<<endl;
    macierz2.print();

    cout<<"Wypelnienie macierzy 5x6:"<<endl;
    for(int i=0;i<macierz1.rows();i++)
    {
        for(int j=0;j<macierz1.cols();j++)
        {
            macierz1.set(i,j,3.5+i*j);
        }
    }
    macierz1.print();
    cout<<"Metoda wypisujaca element [3][4] macierzy 5x6:"<<endl;
    cout<<macierz1.get(3,4)<<endl<<endl;
    macierz macierz3(5,6);
    for(int i=0;i<macierz3.rows();i++)
    {
        for(int j=0;j<macierz3.cols();j++)
        {
            macierz3.set(i,j,2);
        }
    }
    cout<<"Druga macierz 5x6: "<<endl;
    macierz3.print();
    cout<<"Wynik dodawania pierwszej i drugiej macierzy 5x6"<<endl; 
    macierz dodawanie=macierz1.add(macierz3);
    dodawanie.print();
    macierz odejmowanie=macierz3.subtract(macierz1);
    cout<<"Wynik odejmowania pierwszej macierzy 5x6 od drugiej macierzy 5x6"<<endl;
    odejmowanie.print();
    macierz macierz4(6,5);
    for(int i=0;i<macierz4.rows();i++)
    {
        for(int j=0;j<macierz4.cols();j++)
        {
            macierz4.set(i,j,2);
        }
    }
    cout<<"Macierz 6x5:"<<endl;
    macierz4.print();
    macierz iloczyn=macierz1.multiply(macierz4);
    cout<<"Wynik mnozenia pierwszej macierzy 5x6 i macierzy 6x5"<<endl;
    iloczyn.print();
    cout<<"Ilosc kolumn w macierzy wymnozonej wynosi "<<iloczyn.cols()<<" a ilosc wierszy "<<iloczyn.rows()<<endl<<endl;
    iloczyn.store("wynik.txt","wynik");
    cout<<"Wynikiem wywolania metody store() jest plik wynik.txt"<<endl<<endl;
    macierz macierz_z_pliku("wynik");
}
