#include <iostream>
#include <fstream>
#include "lab3.hpp"
using namespace std;

macierz::macierz(int n, int m)
{
    wiersz=n;
    kolumna=m;
    tab=new double *[wiersz];
    for(int i=0;i<wiersz;i++)
        tab[i]=new double[kolumna];
    for (int i=0;i<wiersz;i++)
    {
        for(int j=0;j<kolumna;j++)
        {
            tab[i][j]=0;
        }
    }
            
}
macierz::macierz(int n)
{
    wiersz=n;
    kolumna=n;
    tab=new double *[wiersz];
    for(int i=0;i<wiersz;i++)
        tab[i]=new double[wiersz];
    for (int i=0;i<wiersz;i++)
    {
        for(int j=0;j<wiersz;j++)
        {
            tab[i][j]=0;
        }
    }
}
void macierz::set(int n, int m, double val)
{
    if(n<0 || n>wiersz || m<0 || m>kolumna)
        cout<<"Wyszedles poza zakres tablicy"<<endl;
    else
        tab[n][m]=val;
}
double macierz::get(int n, int m)
{
    if(n<0 || n>wiersz || m<0 || m>kolumna)
    {
        cout<<"Wyszedles poza zakres tablicy"<<endl;
        exit(1);
    }    
    else
        return tab[n][m];
}
macierz macierz::add(macierz mac)
{
    
    if(mac.rows()!=wiersz || mac.cols() !=kolumna)
    {
        cout<<"Proba dodania macierzy o innych wymiarach"<<endl;
        return 0;
    }
    macierz wynik(mac.rows(),mac.cols());
    for(int i=0;i<mac.rows();i++)
    {
        for(int j=0;j<mac.cols();j++)
        {
            wynik.tab[i][j] = mac.tab[i][j]+tab[i][j];
        }   
    }
    return wynik;
    
}
macierz macierz::subtract(macierz mac)
{
    
    if(mac.rows()!=wiersz || mac.cols() !=kolumna)
    {
        cout<<"Proba odejmowania macierzy o innych wymiarach"<<endl;
        return 0;
    }
    macierz roznica(mac.rows(),mac.cols());
    for(int i=0;i<mac.rows();i++)
    {
        for(int j=0;j<mac.cols();j++)
            roznica.tab[i][j]=tab[i][j]-mac.tab[i][j];
    }
    return roznica;

}
macierz macierz::multiply(macierz mac)
{
    if(mac.rows()!=kolumna)
    {
        cout<<"Blad mnozenia."<<endl;
        return 0;
    }
    double wynik;
    macierz iloczyn(wiersz,mac.cols());
    for (int i = 0; i < wiersz; i++)
    {
        for (int j = 0; j < mac.kolumna; j++)
        {
            wynik=0;
            for (int k = 0; k < mac.wiersz; k++)
            {
                wynik+=tab[i][k]*mac.tab[k][j];
            }
            iloczyn.tab[i][j]=wynik;
        }
    }
    return iloczyn;
}
int macierz::cols()
{
    return kolumna;
}
int macierz::rows()
{
    return wiersz;
}
void macierz::print()
{
    for(int i=0;i<wiersz;i++)
    {
        for(int j=0;j<kolumna;j++)
            cout<<"tab["<<i<<"]["<<j<<"] = "<<tab[i][j]<<"   "<<'\t';
        cout<<endl;
    }
    cout<<endl;
}
void macierz::store(string filename, string path)
{
    fstream plik;
    plik.open(path,ios_base::out);
    if(plik.is_open())
    {
        plik<<"Number of rows: "<<rows()<<" Number of cols: "<<cols()<<endl;
        for(int i =0;i<wiersz;i++)
        {
            for(int j =0;j<kolumna;j++)
            {
                plik<<tab[i][j]<<" ";
            }
            plik<<endl;
        }
        plik.close();
    }
    else
    {
        cout<<"Plik nie zostal otwarty. Sprawdz poprawnosc podanej sciezki"<<endl;
    }   
}

macierz::macierz(string path)
{
    fstream plik;
    plik.open(path);
    int wiersz1,kolumna1;
    if(plik.is_open())
    {
        plik>>wiersz1;
        plik>>kolumna1;

        wiersz=wiersz1;
        kolumna=kolumna1;

        tab = new double*[wiersz];
        for (int i=0;i<wiersz;i++)
        {
            tab[i]=new double[kolumna];
        }
        for (int i = 0; i < wiersz; i++)
        {
            for (int j = 0; j < kolumna; j++)
            {
                plik >> tab[i][j];
            }
        }
        plik.close();
    }
    else
    {
        cout<<"Blad otwarca pliku. Sprawdz poprawnosc podanej sciezki"<<endl;
    }
    
};