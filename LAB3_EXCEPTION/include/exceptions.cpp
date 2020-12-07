#include <iostream>

using namespace std;

class LessOrEqualZero : public exception
{
    virtual const char* what() const throw()
    {
        return "ERROR: Rozmiar macierzy mniejszy lub rowny zero.";
    }
};

class LessZero : public exception
{
    virtual const char* what() const throw()
    {
        return "ERROR: Rozmiar macierzy mniejszy od zera.";
    }
};

class WrongSize : public exception
{
    virtual const char* what() const throw()
    {
        return "ERROR: Przekroczono rozmiar tablicy.";
    }
};

class IndexError : public exception
{
    virtual const char* what() const throw()
    {
        return "ERROR: Macierze o roznych wymiarach.";
    }
};

class FileOpen : public exception
{
    virtual const char* what() const throw()
    {
        return "ERROR: Plik nie zostal otwarty. Sprawdz poprawnosc podanej sciezki.";
    }
};