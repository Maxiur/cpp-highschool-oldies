#include <iostream>
#include <ctime>
using namespace std;

void quicksort(int *tablica, int lewy, int prawy)
{
    int v=tablica[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    do
    {
        while (tablica[i]<v) i++;
        while (tablica[j]>v) j--;
        if (i<=j)
        {
            x=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=x;
            i++;
            j--;
        }
    }
    while (i<=j);
    if (j>lewy) quicksort(tablica,lewy, j);
    if (i<prawy) quicksort(tablica, i, prawy);
}

int main()
{
    int *tablica, ilosc;
    tablica= new int [ilosc];
    cin>>ilosc;
    srand(time(NULL));

    for(int i=0;i<ilosc;i++)
    {
        tablica[i]=rand()%10000+1;
    }
    quicksort(tablica, 0, ilosc-1);
    for(int i=0;i<ilosc;i++)
    {
        cout<<tablica[i]<<" ";

    }

    delete [] tablica;
    return 0;
}
