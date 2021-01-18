#include <iostream>

using namespace std;

class macierz
{
    private:
        int wiersz,kolumna;
        double **tab;

    public:
        macierz(int n, int m);
        macierz(int n);
        void set(int n,int m,double val);
        double get(int n,int m);
        macierz add(macierz mac);
        macierz subtract(macierz mac);
        macierz multiply(macierz mac);
        int cols();
        int rows();
        void print();
        void store(string filename, string path);
        macierz(string path);
        macierz operator+(macierz mac);
        macierz operator-(macierz mac);
        macierz operator*(macierz mac);
        bool operator==(macierz mac);
        double operator[](int number);
        friend ostream & operator<<(std:: ostream &out, macierz mac)
        {
            for(int i=0;i<mac.wiersz;i++)
            {
                for(int j=0;j<mac.kolumna;j++)
                    out<<"tab["<<i<<"]["<<j<<"] = "<<mac.tab[i][j]<<"   "<<'\t';
                out<<endl;
            }
            out<<endl;
        }
};