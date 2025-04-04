#include <iostream>
#include <fstream>

using namespace std;

int NWD(int a, int b)
{
    if(b==0)
        return a;
    else
        return NWD(b,a%b);
}

int main()
{
    ifstream file("dane_ulamki.txt");
    float numerator,MINnumerator=12000; //licznik
    float denominator,MINdenominator; //mianownik
    float MIN=12000;
    int counter=0,counter2=0;
    int b=2*2*3*3*5*5*7*7*13;
    long long int SUMnumerator=0;
    for(int i=0; i<1000; i++)
    {
        file>>numerator;
        file>>denominator;
        if(numerator/denominator<MIN)
        {
            MIN=numerator/denominator;
            MINnumerator=numerator;
            MINdenominator=denominator;
        }
        else if(numerator/denominator==MIN && numerator<MINnumerator)
        {
            MIN=numerator/denominator;
            MINnumerator=numerator;
            MINdenominator=denominator;
        }
        if(NWD(numerator,denominator)==1)
            counter++;
        counter2+=numerator/NWD(numerator,denominator);
        SUMnumerator+=(numerator/denominator)*b;
    }
    cout<<MINnumerator<<" "<<MINdenominator;
    cout<<endl<<counter;
    cout<<endl<<counter2;
    cout<<endl<<SUMnumerator;
    return 0;
}
