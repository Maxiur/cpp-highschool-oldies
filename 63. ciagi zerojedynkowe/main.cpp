#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

bool polpierwsza(bool sito[], int a)
{
    for(int i=2;i<1000000;i++)
        if(sito[i])
            if(a%i==0)
                if(sito[a/i])
                    return true;
    return false;
}

long long int binarna_dziesietna(long long int i)
{
    int wynik=0;
    int x=0;
    while(i>0)
    {
        wynik+=(i%10)*pow(2,x);
        x++;
        i/=10;
    }
    return wynik;
}

bool dwucykliczny(string c)
{
    if(c.size()%2!=0)
        return false;
    for(int i=0; i<(c.size()/2); i++)
    {
        if(c[i]!=c[i+c.size()/2])
            return false;
    }
    return true;
}

bool jedynkiobok(string c)
{
    for(int i=0; i<c.size()-1; i++)
    {
        if(c[i]=='1' && c[i+1]=='1')
            return true;
    }
    return false;
}

int main()
{
    ifstream wejscie("ciagi.txt");
    ofstream wyjscie1("wynik1.txt");
    ofstream wyjscie2("wynik2.txt");
    ofstream wyjscie3("wynik3.txt");

    long long int ciag;
    int counter=0;

    bool sito[1000000];
    for(int i=0; i<1000000; i++)
        sito[i]=true;
    sito[0]=false;
    sito[1]=false;
    for(int i=2; i<1000; i++)
        if(sito[i]==true)
            for(int j=2*i; j<1000000; j=j+i)
                sito[j]=false;
    int najm=999999999, najw=0;
    for(int i=0; i<1000; i++)
    {
        wejscie>>ciag;
        if(polpierwsza(sito,binarna_dziesietna(ciag)))
            {
                counter++;
                if(binarna_dziesietna(ciag)>najw) najw=binarna_dziesietna(ciag);
                if(binarna_dziesietna(ciag)<najm) najm=binarna_dziesietna(ciag);
            }
    }
    cout<<counter<<" "<<najw<<" "<<najm;
    return 0;
}
