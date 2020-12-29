#include <iostream>

using namespace std;

class TooLongName : public exception
{
    virtual const char *what() const throw()
    {
        return "Podane imie jest za dlugie.";
    }
};

class DeparmentError : public exception
{
    virtual const char *what() const throw()
    {
        return "Podana nazwa departamentu jest nieprawidlowa.";
    }
};

class PositionError : public exception
{
    virtual const char *what() const throw()
    {
        return "Podana nazwa stanowiska jest nieprawidlowa.";
    }
};

class SalaryError : public exception
{
    virtual const char *what() const throw()
    {
        return "Podana wartosc zarobkow jest nieprawidlowa.";
    }
};

class IDError : public exception
{
    virtual const char *what() const throw()
    {
        return "Pracownik o podanym ID nie istnieje.";
    }
};

class FileOpen : public exception
{
    virtual const char* what() const throw()
    {
        return "ERROR: Plik nie zostal otwarty. Sprawdz poprawnosc podanej sciezki.";
    }
};
