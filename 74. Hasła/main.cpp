#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool czteryascii(string a)
{
    for(int i=0;i+3<a.size();i++)
    {
        int a_max=0;
        int a_max2=0;
        int a_min=300;
        int a_min2=300;

        if((int)a[i]>a_max)
        {
            a_max2=a_max;
            a_max=(int)a[i];
        }
        if((int)a[i+1]>a_max)
        {
            a_max2=a_max;
            a_max=(int)a[i+1];
        }
        if((int)a[i+2]>a_max)
        {
            a_max2=a_max;
            a_max=(int)a[i+2];
        }
        if((int)a[i+3]>a_max)
        {
            a_max2=a_max;
            a_max=(int)a[i+3];
        }

        if((int)a[i]<a_min)
        {
            a_min2=a_min;
            a_min=(int)a[i];
        }
        if((int)a[i+1]<a_min)
        {
            a_min2=a_min;
            a_min=(int)a[i+1];
        }
        if((int)a[i+2]<a_min)
        {
            a_min2=a_min;
            a_min=(int)a[i+2];
        }
        if((int)a[i+3]<a_min)
        {
            a_min2=a_min;
            a_min=(int)a[i+3];
        }

        if(a_max-a_min==3 && a_max-a_max2==1 && a_min2-a_min==1)
            return true;
    }

    return false;
}

void sortowanie(string a, string b)
{
    int n=min(a.size(),b.size());
    for(int i=0; i<n; i++)
        if((int)(a[i]>(int)b[i]))
        {
            swap(a[i],b[i]);
            break;
        }
}

bool cyfry(string a)
{
    for(int i=0; i<a.size(); i++)
    {
        if((int)a[i]>=65 && (int)a[i]<=90)
            return false;
        if((int)a[i]>=97 && (int)a[i]<=122)
            return false;
    }
    return true;
}

bool takiesame(string a, string b)
{
    if(a.size()!=b.size())
        return false;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]!=b[i])
            return false;
    }
    return true;
}

int main()
{
    ifstream wejscie("hasla.txt");
    string t[200];
    int licznik=0;
    for(int i=0; i<200; i++)
    {
        wejscie>>t[i];
        //    if(cyfry(haslo1))
        //        licznik++;
        if(czteryascii(t[i]))
            cout<<t[i]<<endl;
    }
    cout<<"-----------------------\n";
    for(int i=0; i<200; i++)
        for(int j=i+1; j<200; j++)
            if(takiesame(t[i],t[j]))
                cout<<t[i]<<endl;
    cout<<endl<<licznik;




    return 0;
}
