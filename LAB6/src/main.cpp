#include <iostream>
#include <string>
#include "functions.hpp"


using namespace std;

int main()
{
    string imie;
    string nazwisko;
    string departament;
    string stanowisko;
    double pensja;
    string department;
    string id;
    double salary;
    HRMS* hrms=new HRMS();
    cout<<'\t'<<'\t'<<'\t'<<"MENU"<<endl;
    while(1)
    {
        cout<<"1. Dodaj pracownika"<<endl;
        cout<<"2. Wypisz pracownikow danego departamentu"<<endl;
        cout<<"3. Zmien wynagrodzenie danego pracownika"<<endl;
        cout<<"4. Wypisz wynagrodzenia wszystkich pracownikow"<<endl;
        cout<<"5. Wypisz posortowane wynagrodzenia wszystkich pracownikow"<<endl;
        cout<<"6. Wypisz wszystkich pracownikow"<<endl;
        cout<<"7. Zapisz dane do pliku"<<endl;
        cout<<"8. Zakoncz dzialanie programu"<<endl;

        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                try
                {
                    cout<<endl<<"Imie: ";
                    cin>>imie;
                    if(imie.size()>15)
                    {
                        TooLongName error;
                        throw error;
                    }
                    cout<<"Nazwisko: ";
                    cin>>nazwisko;
                    cout<<"Departament: ";
                    cin>>departament;
                    if(departament.size()>20)
                    {
                        DeparmentError error;
                        throw error;
                    }
                    cout<<"Stanowisko: ";
                    cin>>stanowisko;
                    if(stanowisko.size()>20)
                    {
                        PositionError error;
                        throw error;
                    }
                    cout<<"Wynagrodzenie: ";
                    cin>>pensja;
                    if(pensja>1000000)
                    {
                        SalaryError error;
                        throw error;
                    }
                    cout<<endl;
                }
                catch(exception &e)
                {
                    cout<< e.what() << '\n';
                }
                Employee *employee = new Employee(imie,nazwisko,departament,stanowisko);
                hrms->add(employee,departament,pensja);
                break;
            }
            case 2:
                try
                {
                    cout<<endl<<"Podaj departament: ";
                    cin>>department;
                    if(departament.size()>20)
                    {
                        DeparmentError error;
                        throw error;
                    }

                }
                catch(const std::exception& e)
                {
                    cout<< e.what() << '\n';
                }
                cout<<endl;
                hrms->printDepartment(department);
                break;
            case 3:
                try
                {
                    cout<<endl<<"Podaj ID pracownika: ";
                    cin>>id;
                    if(!(hrms->salaries[id]))
                    {
                        IDError error;
                        throw error;
                    }
                    cout<<"Nowe wynagrodzenie: ";
                    cin>>salary;
                    if(salary>1000000)
                    {
                        SalaryError error;
                        throw error;
                    }
                }
                catch(const std::exception& e)
                {
                    cout<< e.what() << '\n';
                }
                cout<<endl;
                hrms->changeSalary(id,salary);
                break;
            case 4:
                cout<<endl;
                hrms->printSalaries();
                break;
            case 5:
                cout<<endl;
                hrms->printSalariesSorted();
                break;
            case 6:
                cout<<endl;
                hrms->print();
                break;
            case 7:
                hrms->store("dane.txt", "dane");
                cout<<endl;
                cout<<"Dane zostaly zapisane do pliku dane.txt"<<endl;
                cout<<endl;
                break;
            case 8:
                exit(0);
                break;
            default:
                cout<<"Wybrano zla opcje. Sprobuj ponownie."<<endl;
                cout<<endl;
                break;
        }
    }
    
    return 0;
}