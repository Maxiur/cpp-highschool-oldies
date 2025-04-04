#include <iostream>
#include <cmath>
using namespace std;

void nabinarne(int a, int s)
{
   unsigned int t[100]={0};
   int i=0;
   while(a>0)
   {
       t[i]=a%s;
       a=a/s;
       i++;
   }
}

int iloscjedynek(int a)
{
   unsigned int t[100]={0};
   int i=0;
   int counter=0;
   while(a>0)
   {
       t[i]=a%2;
       a=a/2;
       i++;
   }
   for(int j=i-1;j>=0;j--)
   {
       if(t[i]==1)
        counter++;
   }
   return counter;
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

int Fibonacci(int n)
{
    if(n==1 || n==2)
        return 1;
    return Fibonacci(n-1)+Fibonacci(n-2);
}

int main()
{
    cout<<Fibonacci(10)<<endl;
    cout<<Fibonacci(20)<<endl;
    cout<<Fibonacci(30)<<endl;
    cout<<Fibonacci(40)<<endl;
    for(int i=1;i<=40;i++)
    {
        if(iloscjedynek(nabinarne(Fibonacci(i),2)));
        cout<<endl;

    }

    return 0;
}
