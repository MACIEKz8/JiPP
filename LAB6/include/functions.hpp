#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include "exceptions.cpp"
#include <fstream>

using namespace std;

class Employee
{
    private: 
        string ID;
        string name;
        string surname;
        string departmentID;
        string position;
    public:
        Employee(string imie, string nazwisko, string department, string Position)
        {
            static int ID_counter=1;
            ID=to_string(ID_counter);
            name=imie;
            surname=nazwisko;
            departmentID=department;
            position=Position;
            ID_counter++;
        }

        void get(string &id,string &imie,string &nazwisko,string &departament,string &pozycja)
        {
            id=ID;
            imie=name;
            nazwisko=surname;
            departament=departmentID;
            pozycja=position;
        }

        string getID()
        {
            return ID;
        }

        friend ostream & operator<<(std:: ostream &out, Employee temp)
        {
            string ID,name,surname,departmentID,position;
            temp.get(ID,name,surname,departmentID,position);
            std::cout.flags(std::ios_base::internal);
            std::cout.width(4);
            out<<ID;
            std::cout.width(15);
            out<<name;
            std::cout.width(25);
            out<<surname;
            std::cout.width(20);
            out<<departmentID;
            std::cout.width(20);
            out<<position;

            return out;
        }

};

class HRMS 
{
    private:
        vector<Employee> employees;
        map<string,string> ID_map;
        
    public:
        map<string,double> salaries;
        HRMS()
        {

        }
        ~HRMS();

        static bool ValueSort(const pair<string, double> &x, const pair<string, double> &y)
        {
            return (x.second > y.second);
        }

        void add(Employee *employee, string department_ID, double SALARY)
        {
            employees.push_back(*employee);
            ID_map[employee->getID()]=department_ID;
            salaries[employee->getID()]=SALARY;
        }
        void printDepartment(string departmentID)
        {
            std::cout.width(4);
            cout<<"ID";
            std::cout.width(15);
            cout<<"NAME";
            std::cout.width(25);
            cout<<"SURNAME";
            std::cout.width(20);
            cout<<"DEPARTMENT";
            std::cout.width(20);
            cout<<"POSITION";
            std::cout.width(10);
            cout<<"SALARY"<<endl;
            cout<<"______________________________________________________________________________________________"<<endl;
            map<string,string>::iterator counter=ID_map.begin();
            for(counter;counter!=ID_map.end();counter++)
            {
                if(counter->second==departmentID)
                {
                    int number=stoi(counter->first);
                    cout<<employees[number-1]<<" ";
                    std::cout.flags(std::ios_base::internal);
                    std::cout.width(8);
                    cout<<salaries[counter->first]<<endl;
                }
            }


        }
        void changeSalary(string employeeID, double salary)
        {
            salaries[employeeID]=salary;
        }
        void printSalaries()
        {
            std::cout.width(10);
            cout<<"SALARY";
            std::cout.width(5);
            cout<<"ID";
            std::cout.width(15);
            cout<<"NAME";
            std::cout.width(25);
            cout<<"SURNAME";
            std::cout.width(20);
            cout<<"DEPARTMENT";
            std::cout.width(20);
            cout<<"POSITION"<<endl;
            cout<<"_______________________________________________________________________________________________"<<endl;
            map<string,double>::iterator counter=salaries.begin();
            for(counter;counter!=salaries.end();counter++)
            {
                int number=stoi(counter->first);
                std::cout.width(10);
                cout<<salaries[counter->first]<<" ";
                cout<<employees[number-1]<<" "<<endl;
            }
        }
        void printSalariesSorted()
        {
            std::cout.width(8);
            cout<<"SALARY";
            std::cout.width(5);
            cout<<"ID";
            std::cout.width(15);
            cout<<"NAME";
            std::cout.width(25);
            cout<<"SURNAME";
            std::cout.width(20);
            cout<<"DEPARTMENT";
            std::cout.width(20);
            cout<<"POSITION"<<endl;
            cout<<"______________________________________________________________________________________________"<<endl;
            vector<pair<string,double>> temp;
            map<string,double>::iterator counter=salaries.begin();
            for(counter;counter!=salaries.end();counter++)
            {
                temp.push_back(make_pair(counter->first,counter->second));
            }
            sort(temp.begin(),temp.end(),ValueSort);
            for(int i=0;i!=temp.size();i++)
            {
                int number=stoi(temp[i].first);
                std::cout.width(8);
                cout<<temp[i].second<<" "<<employees[number-1]<<endl;
            }
        }
        void print()
        {
            std::cout.width(4);
            cout<<"ID";
            std::cout.width(15);
            cout<<"NAME";
            std::cout.width(25);
            cout<<"SURNAME";
            std::cout.width(20);
            cout<<"DEPARTMENT";
            std::cout.width(20);
            cout<<"POSITION"<<endl;
            cout<<"______________________________________________________________________________________________"<<endl;
            for(int i=0;i!=employees.size();i++)
            {
                cout<<employees[i]<<endl;
            }
        }
        void store(string filename, string path)
        {
            fstream plik;
            plik.open(path,ios_base::out);
            try
            {
                if(plik.is_open())
                {
                    std::cout.width(4);
                    plik<<"ID ";
                    std::cout.width(15);
                    plik<<"NAME ";
                    std::cout.width(25);
                    plik<<"SURNAME ";
                    std::cout.width(20);
                    plik<<"DEPARTMENT ";
                    std::cout.width(20);
                    plik<<"POSITION "<<endl;
                    plik<<"______________________________________________________________________________________________"<<endl;
                    for(int i=0;i!=employees.size();i++)
                    {
                        plik<<(employees[i])<<endl;
                    }
                    plik.close();
                }
                else
                {
                    FileOpen error;
                    throw error;
                }
            }
            catch(exception &e)
            {
                cout << e.what() << '\n';
            }
        }
};
