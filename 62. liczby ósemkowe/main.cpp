#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int wystepowanie6(int a)
{
    int wynik=0;
    while(a>0)
    {
        if(a%10==6)
            wynik++;
        a/=10;
    }
    return wynik;
}

int wystepowanie68(int a)
{
    int wynik=0;
    while(a>0)
    {
        if(a%8==6)
            wynik++;
        a/=10;
    }
    return wynik;
}

int osemkowy_dziesietny(int a)
{
    int x=0;
    int wynik=0;
    while(a>0)
    {
        wynik+=(a%10)*pow(8,x);
        a=a/10;
        x++;
    }
    return wynik;
}

int dziesietny_osemkowy(int a)
{

}

int main()
{
    int najmniejsza=9999999;
    int najwieksza=0;
    int number8;
    int number10;
    ifstream wejscie1("liczby1.txt");
    ifstream wejscie2("liczby2.txt");
    int poczatekciagu=0;
    int counter=1,counter2=0,counter3=0,counter6=0,counter68=0;
    int pierwsza;
    int maks=0,makspoczatek;
    for(int i=0; i<1000; i++)
    {
        wejscie1>>number8;
        wejscie2>>number10;
        if(osemkowy_dziesietny(number8)==number10)
            counter2++;
        if(osemkowy_dziesietny(number8)>number10)
            counter3++;
        counter6+=wystepowanie6(number10);
        counter68+=wystepowanie68(number10);

        if(number8>najwieksza)
            najwieksza=number8;
        if(number8<najmniejsza)
            najmniejsza=number8;


        if(counter==1)
            pierwsza=poczatekciagu;
        if(poczatekciagu<=number10)
        {
            counter++;
            poczatekciagu=number10;
        }
        else
        {
            if(counter>maks)
                {
                    maks=counter;
                    makspoczatek=pierwsza;
                }
            counter=1;
            poczatekciagu=number10;
        }


    }
    cout<<makspoczatek<<" "<<maks;
    cout<<endl<<najmniejsza<<" "<<najwieksza;
    cout<<endl<<counter2<<" "<<counter3;
    cout<<endl<<counter6<<" "<<counter68;
    return 0;
}
