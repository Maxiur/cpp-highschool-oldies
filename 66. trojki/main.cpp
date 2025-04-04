#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool czy_trojkat(int a, int b, int c)
{
    if(a+b>c && a+c>b && c+b>a)
        return true;
    return false;
}

bool trojkat_prostokatny(int a, int b, int c)
{
    if(a*a+b*b==c*c || a*a+c*c==b*b || c*c+b*b==a*a)
        return true;
    return false;
}

bool IsPrime(int a)
{
    if(a<2)
        return false;
    for(int i=2; i<=sqrt(a); i++)
        if(a%i==0)
            return false;
    return true;
}

bool suma_trzeciej(int a, int b, int c)
{
    int result=0;
    while(a>0)
    {
        result+=a%10;
        a/=10;
    }
    while(b>0)
    {
        result+=b%10;
        b/=10;
    }
    if(result==c)
        return true;
    return false;
}

int main()
{
    ifstream file("trojki.txt");
    int a,b,c;
    int d=2,e=2,f=2;
    int counter=0,dlugosc=0;
    int MAX=0;
    for(int i=0; i<1000; i++)
    {
        //d=a;
        //e=b;
        //f=c;
        file>>a;
        file>>b;
        file>>c;
        //if((IsPrime(a) && IsPrime(b) && a*b==c))
        //   cout<<a<<" "<<b<<" "<<c<<endl;

        //if(trojkat_prostokatny(d,e,f) && trojkat_prostokatny(a,b,c))
        //{
        //    cout<<d<<" "<<e<<" "<<f<<endl;
        //    cout<<a<<" "<<b<<" "<<c<<endl;
        //}

        if(czy_trojkat(a,b,c))
        {
            counter++;
            dlugosc++;
        }
        else
        {
            if(dlugosc>MAX)
                MAX=dlugosc;
            dlugosc=0;
        }

    }
    cout<<counter<<" "<<MAX;
    return 0;
}
