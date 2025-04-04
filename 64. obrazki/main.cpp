#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define RZM 20
typedef short obrazek[RZM+1][RZM+1];
typedef istreambuf_iterator<char> literka;

int main()
{
    ifstream wejscie("dane_obrazki.txt");
    string obrazek[21][21];
    int jedynki=0;
    int maks=0;
    int counter=0;
    for(int i=0; i<200; i++)
    {
        for(int i=0;i<21;i++)
        {
            for(int j=0;j<21;j++)
            wejscie.get(obrazek[i][j]);
        }

        for(int i=0; i<RZM; i++)
        {
            for(int j=0; j<RZM; j++)
                if(obrazek[i][j]=="1")
                    jedynki++;
        }
        if(jedynki>200)
        {
            counter++;
            if(jedynki>maks)
                maks=jedynki;
        }
        jedynki=0;
    }

    cout<<counter<<" "<<maks;

    return 0;
}
