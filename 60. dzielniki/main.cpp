#include <iostream>
#include <fstream>
using namespace std;

int dzielniki(int a)
{
    int counter=0;
    for(int i=1; i<=a; i++)
    {
        if(a%i==0)
            counter++;
    }
    return counter;
}

bool wzglednie_pierwsze(int a, int b)
{
    for(int k=2; k<=a || k<=b; k++)
    {
        if(a%k==0 && b%k==0)
            return false;
    }
    return true;
}

int main()
{
    ifstream wejscie("liczby.txt");
    int lastnumber1,lastnumber2;
    int number;
    int counter=0;
    int maks=0;
    int t[200];
    for(int i=0; i<200; i++)
    {
        wejscie>>number;
        if(number<1000)
        {
            counter++;
            lastnumber2=lastnumber1;
            lastnumber1=number;
        }
        if(dzielniki(number)==18)
        {
            cout<<endl<<number;
            for(int j=1; j<=number; j++)
            {
                if(number%j==0)
                    cout<<" "<<j;
            }
        }
        t[i]=number;
    }
    for(int i=0; i<200; i++)
        for(int j=i+1; j<200; j++)
            if(wzglednie_pierwsze(t[i],t[j])==false)
                t[i]=0;
    for(int i=0; i<200; i++)
        if(t[i]>maks)
            maks=t[i];



    cout<<endl<<counter<<" dwie ostatnie: "<<lastnumber2<<" "<<lastnumber1;

    cout<<endl<<maks;

    return 0;
}
