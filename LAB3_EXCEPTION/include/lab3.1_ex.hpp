#include <iostream>
#include <fstream>
#include "lab3_ex.hpp"
#include "exceptions.cpp"
using namespace std;

macierz::macierz(int n, int m)
{
    wiersz=n;
    kolumna=m;
    try
    {
        if (n<=0 || m<=0)
        {
            LessOrEqualZero error;
            throw error;
        }
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
    catch(exception &e)
    {
        cout<<e.what()<<endl;
    }
    
    
            
}
macierz::macierz(int n)
{
    wiersz=n;
    kolumna=n;
    try
    {
        if(n<=0)
        {
            LessOrEqualZero error;
            throw error;
        }
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
    catch(exception &e)
    {
        cout<<e.what()<<endl;
    }
}
void macierz::set(int n, int m, double val)
{
    try
    {
        if( n>wiersz || m>kolumna)
        {
            WrongSize error;
            throw error;
        }
        else if(n<0 || m<0)
        {
            LessZero error;
            throw error;
        }
        else
            tab[n][m]=val;
    }
    catch(exception &e)
    {
        cout<< e.what() <<endl;
    }
    
    
}
double macierz::get(int n, int m)
{
    try
    {
        if( n>wiersz || m>kolumna)
        {
            WrongSize error;
            throw error;
        }    
        else if(n<0 || m<0)
        {
            LessZero error;
            throw error;
        }
        else
            return tab[n][m];
    }
    catch(exception &e)
    {
        cout<< e.what() <<endl;
    }    
}

macierz macierz::add(macierz mac)
{
    try
    {
        if(mac.rows()!=wiersz || mac.cols() !=kolumna)
        {
            IndexError error;
            throw error;
        }
        
    }
    catch(exception &e)
    {
        cout<< e.what() <<endl;
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
    try
    {
        if(mac.rows()!=wiersz || mac.cols() !=kolumna)
        {
            IndexError error;
            throw error;
        }
    }
    catch(exception &e)
    {
        cout<< e.what() <<endl;
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
    try
    {
        if(mac.rows()!=kolumna)
        {
            IndexError error;
            throw error;
        }
    }
    catch(exception &e)
    {
        cout<< e.what() <<endl;
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
    try
    {
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
            FileOpen error;
            throw error;
        }   
    }
    catch(const std::exception& e)
    {
        cout<< e.what() <<endl;
    }
}

macierz::macierz(string path)
{
    fstream plik;
    plik.open(path);
    int wiersz1,kolumna1;
    try
    {
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
            FileOpen error;
            throw error;
        }
    }
    catch(const std::exception& e)
    {
        cout<< e.what() <<endl;
    }
};