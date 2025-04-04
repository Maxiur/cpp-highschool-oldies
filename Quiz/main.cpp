#include <iostream>
#include "pytania.h"
using namespace std;

int main()
{
    Pytanie p[5];
    int suma=0;
    for(int i=0;i<5;i++)
    {
    p[i].numer_pyt=i+1;
    p[i].wczytaj();
    p[i].zadaj();
    p[i].sprawdz();
    suma+=p[i].punkt;
    }

    cout<<suma;
    return 0;
}
