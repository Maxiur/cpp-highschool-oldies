#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

string napis(string a, string b)
{
    string literki="";
    while(a!=b && !b.empty())
    {
        literki.insert(0,1,b.back());
        b.pop_back();
    }
    if(b.empty())
        return "";
    return literki;
}

string zakonczenie(string a, string b)
{
    string koniec="";
    int d=min(a.size(),b.size());
    {
    for(int i=1;i<=d;i++)
            if(a[a.size()-i]==b[b.size()-i])
                koniec.insert(0,1,a.size()-i);
            else
                break;
    }
    return koniec;
}

int main()
{
    ifstream wejscie("napisy.txt");
    string napis1,napis2;
    int counter=0;
    int MAX=0;
    for(int i=0; i<200; i++)
    {
        wejscie>>napis1;
        wejscie>>napis2;

        //if(napis1.size()>=3*napis2.size() || napis2.size()>=3*napis1.size())
        //{
        //    counter++;
        //    if(counter==1)
        //        cout<<napis1<<" "<<napis2<<endl;
        //}
        //if(napis2.size()>napis1.size())
        //   if(!napis(napis1,napis2).empty())
        //        cout<<napis1<<" "<<napis2<<" "<<napis(napis1,napis2)<<endl;

        string wynik=zakonczenie(napis1,napis2);
        if(!wynik.empty())
            if(wynik.size()>MAX)
                MAX=wynik.size();
        if(wynik.size()==15)
            cout<<napis1<<" "<<napis2<<endl;
    }
    cout<<MAX;
    return 0;
}
