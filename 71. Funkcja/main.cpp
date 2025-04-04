#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

ifstream enter("funkcja.txt");

class Funkcja
{
public:

    long double a0;
    long double a1;
    long double a2;
    long double a3;

    void wczytaj()
    {
        enter>>a0>>a1>>a2>>a3;
    }

    void wyswietl()
    {
        cout<<a0<<" "<<a1<<" "<<a2<<" "<<a3<<endl;
    }

    long double f(double x)
    {
        return a0+a1*x+a2*x*x+a3*x*x*x;
    }
    double miejsce_zerowe(double lewy, double prawy)
{
    double dokladnosc=0.000001;
    double srodek=(lewy+prawy)/2;
    if(lewy>prawy)
        swap(lewy,prawy);
    while(prawy-lewy>dokladnosc)
    {
        srodek=(lewy+prawy)/2;
        if(f(srodek)*f(lewy)<0)
            prawy=srodek;
        else
            lewy=srodek;
    }
    return srodek;
}

};


int main()
{
    Funkcja f1,f2,f3,f4,f5;
    f1.wczytaj();
    f2.wczytaj();
    f3.wczytaj();
    f4.wczytaj();
    f5.wczytaj();
    //double x=1.5;
    //if(x>=0 && x<1)
    //cout<<f(f1.a0,f1.a1,f1.a2,f1.a3,x);
    // if(x>=1 && x<2)
    // cout<<f(f2.a0,f2.a1,f2.a2,f2.a3,x);
    // if(x>=2 && x<3)
    //   cout<<f(f3.a0,f3.a1,f3.a2,f3.a3,x);
    //  if(x>=3 && x<4)
    //    cout<<f(f4.a0,f4.a1,f4.a2,f4.a3,x);
    double x=4;
    double h=0.001;
    double MAX=0;
    double MAXF=0;
    while(x>=4 && x<5)
    {
        if(f5.f(x)>MAXF)
        {
            MAX=x;
            MAXF=f5.f(x);
        }
        x+=h;
    }
    cout<<MAX<<" "<<MAXF;

    cout<<endl<<setprecision(5)<<f1.miejsce_zerowe(0,1);
    cout<<endl<<setprecision(6)<<f3.miejsce_zerowe(2,3);
    cout<<endl<<setprecision(6)<<f4.miejsce_zerowe(3,4);
    cout<<endl<<setprecision(6)<<f5.miejsce_zerowe(4,5);

    return 0;
}
