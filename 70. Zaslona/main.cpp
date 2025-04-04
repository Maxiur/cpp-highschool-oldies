#include <iostream>
#include <iomanip>
using namespace std;

long double f(float x)
{
    return (x*x*x*x)/500-((x*x)/200)-(3/250);
}

long double g(float x)
{
    return -(x*x*x)/30+(x/20)+(1/6);
}

int main()
{
    long double dg=32*2/3;
    long double df=19*61/125;
    long double pole=0;
    int precision=10000;
    for(int i=0;i<precision;i++)
    {
        pole+=(df/precision)*f(df/precision);
    }
    for(int i=0;i<precision;i++)
    {
        pole+=(dg/precision)*g(dg/precision);
    }
    cout<<pole;
    return 0;
}
