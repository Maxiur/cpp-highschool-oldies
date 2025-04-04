#include <iostream>
#include <fstream>

bool ciag_arytmetyczny(int c[], int r, int d)
{
    for(int i=0; i<d-1; i++)
    {
        if(c[i+1]!=c[i]+r)
            return false;
    }
    return true;
}
using namespace std;

int main()
{
    int dlugosc;
    int maks=0;
    int najwieksza;
    int counter;
    ifstream wejscie("ciagi.txt");
    ifstream wejscie2("bledne.txt");
    ofstream wyjscie("wynik2.txt");
    int szesciany[101];
    for(int j=1;j<101;j++)
    {
        szesciany[j]=j*j*j;
        cout<<szesciany[j]<<endl;
    }
    for(int i=0; i<100; i++)
    {
        wejscie>>dlugosc;
        int ciag[dlugosc];
        for(int j=0; j<dlugosc; j++)
            wejscie>>ciag[j];
        int roznica=ciag[1]-ciag[0];
        if(ciag_arytmetyczny(ciag,roznica,dlugosc))
        {
            counter++;
            if(roznica>maks)
                maks=roznica;
        }
        najwieksza=0;
        for(int j=0;j<dlugosc;j++)
            for(int k=1;k<101;k++)
            if(szesciany[k]==ciag[j])
                if(ciag[j]>najwieksza)
                    najwieksza=ciag[j];
        if(najwieksza>0)
            wyjscie<<najwieksza<<endl;
    }
    for(int i=0;i<20;i++)
    {
        int dlugosc2;
        wejscie2>>dlugosc2;
        int ciag2[dlugosc2];
        for(int j=0; j<dlugosc2; j++)
            wejscie2>>ciag2[j];
        for(int j=0;j<dlugosc2;j++)
        {
            if(dlugosc2-1==j)
            cout<<ciag2[j]<<" {"<<(ciag2[j]-ciag2[j-1])<<"} ,"<<endl;
            else
            cout<<ciag2[j]<<" {"<<(ciag2[j+1]-ciag2[j])<<"} ,"<<endl;
        }
        cout<<"--------------------------------------------\n";
    }

    cout<<endl<<counter<<" "<<maks;

    getchar();
    cin.ignore();
    return 0;
}
