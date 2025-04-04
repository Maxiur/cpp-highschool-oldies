#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

bool dlugosc(string a, string b)
{
    return a.size()<=b.size();
}   //czy pierwszy element jest mniejszy od drugiego (dlugosc)

bool mutation(string a)
{
    int i=0;
    while(a[i]!='A' && a[i+1]!='A' && i!=a.size()-1)
        i++;
    int j=i+1;
    while(a[j]!='B' && a[j+1]!='B' && j!=a.size()-1)
        j++;

}

string gen(string a)
{
    for(int i=0;i<a.size()-1;i++)
    {while(a[i]!='A' && a[i+1]!='A')
        i++;
    a.erase(0,i-1);
    while(a[i]!='B' && a[i+1]!='B')
        i++;
    a.erase(i+2,)
    }
}

int main()
{
    ifstream file("dane_geny.txt");
    string genotypes[1000];
    int amount_genotypes[1000];
    int TEMP=1;
    int MAX=0;
    int counter=0,counter2=0;
    for(int i=0; i<1000; i++)
    {
        file>>genotypes[i];
        amount_genotypes[i]=1;
        if(mutation(genotypes[i]))
            counter2++;
    }
    sort(genotypes, genotypes+1000, dlugosc);
    for(int i=0; i<999; i++)
            if(genotypes[i].size()==genotypes[i+1].size())
                TEMP++;
            else if(genotypes[i].size()!=genotypes[i+1].size())
            {
                counter++;
                if(TEMP>MAX)
                    MAX=TEMP;
                TEMP=1;
            }

   cout<<counter<<" "<<MAX<<" "<<counter2po;
    return 0;
}
