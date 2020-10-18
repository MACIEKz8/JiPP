#include <iostream>
#include <cstring>

using namespace std;

int palindrom(int n, char** tab)
{
    string ciag = tab[1];
    char znak;
    int ile=ciag.length();

    for(int i=0;i<ile;i++)
    {
        znak=tab[1][i];
        if(znak!=ciag[ile-1])
        {
            cout<<"Podany ciag znakow nie jest palindromem tekstowym";
            return 0;
        }
        ile--;
    }
    cout<<"Podany ciag znakow jest palindromem tekstowym"<<endl;
    return 0;
}
int main(int argc, char* argv[])
{
    palindrom(argc,argv);

    return 0;
}