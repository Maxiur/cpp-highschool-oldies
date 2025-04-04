#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

bool dwie(string a)
{
    for(int i=0;i<a.size()-1;i++)
        if(a[i]==a[i+1])
            return true;
    return false;
}

void statystyka(int alfabet[], float suma)
{
    for(int i=65,j=0;i<=90;i++,j++)
        cout<<(char)i<<": "<<alfabet[j]<<" ("<<fixed<<setprecision(2)<<(alfabet[j]/suma*100)<<"%)"<<endl;
}

int main()
{
    ifstream wejscie("tekst.txt");
    string slowo;
    int alfabet[26]={0};
    int suma=0;
    for(int i=0;i<1876;i++)
    {
        wejscie>>slowo;
        suma+=slowo.size();
        //if(dwie(slowo))
        //    counter++;
        for(int j=0;j<slowo.size();j++)
                alfabet[(int)slowo[j]-65]++;
    }
    statystyka(alfabet,suma);
    return 0;
}
