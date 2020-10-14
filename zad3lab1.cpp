#include <iostream>

using namespace std;

int main()
{
    float masa_ciala, wzrost, BMI;
    cout <<"Podaj wzrost w centymetrach: ";
    cin>>wzrost;
    cout <<"Podaj wage w kilogramach: ";
    cin>>masa_ciala;

    BMI = (masa_ciala)/((wzrost/100)*(wzrost/100));
    cout <<"Twoje BMI wynosi: "<<BMI<<endl;
    if (BMI<16)
        cout <<"Jestes wyglodzony!!!";
    else if(BMI>16 && BMI <17)
        cout <<"Jestes wychudzony!";
    else if(BMI>=17 && BMI <18.5)
        cout <<"Masz niedowage!";
    else if (BMI>=18.5 && BMI<25)
        cout <<"Twoje BMI jest prawidlowe!";
    else if (BMI>=25 && BMI<30)
        cout <<"Masz nadwage!";
    else if (BMI>=30 && BMI<35)
        cout <<"Masz I stopien otylosci!";
    else if (BMI>=35 && BMI<40)
        cout <<"Masz II stopien otylosci!";
    else 
        cout <<"Masz skrajna otylosc!";

    cout<<endl<<"Nacisnij dowolny klawisz, aby zakonczyc program";
    getchar();
    return 0;
} 