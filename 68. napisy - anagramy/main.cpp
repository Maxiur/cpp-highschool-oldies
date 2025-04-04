#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool jednolity(string a, string b)
{
    if(a.size()!=b.size())
        return false;
    for(int i=0; i<a.size()-1; i++)
        if((int)a[i]!=(int)b[i])
            return false;
    return true;
}

bool anagram(string a, string b)
{
    int t1[256]= {0}, t2[256]= {0};
    if(a.size()!=b.size())
        return false;
    for(int i=0,j=a.size(); i<j; i++)
    {
        t1[(int)a[i]]++;
        t2[(int)b[i]]++;
    }
    for(int i=0; i<256; i++)
    {
        if(t1[i]!=t2[i])
            return false;
    }
    return true;
}
int main()
{
    ifstream file("dane_napisy.txt");
    string a,b;
    int counter=0;
    int counter2=0;
    int k=0;
    int MAX=0;
    string t1[1000];
    string t2[1000];

    for(int i=0; i<1000; i++)
    {
        file>>a;
        file>>b;
        t1[i]=a;
        t2[i]=b;
        if(jednolity(a,b))
            counter++;
        if(anagram(a,b))
            counter2++;
    }
    for(int i=0; i<1000; i++)
        {
            for(int j=i; j<1000; j++)
            if(anagram(t1[i],t1[j]) || anagram(t1[i],t2[j]))
            {
                k++;
                if(k>MAX)
                    MAX=k;
            }
        k=0;
        }



    cout<<counter<<" "<<counter2<<" "<<MAX;

    return 0;
}
