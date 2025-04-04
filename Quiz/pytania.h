#include <iostream>
using namespace std;

class Pytanie
{
public:

    string tresc;
    string a,b,c,d;
    int numer_pyt;
    string poprawna;
    string odpowiedz;
    int punkt;

    void wczytaj(); //wczytywanie pytania
    void zadaj(); //zadaje pytanie
    void sprawdz(); //sprawdza odpowiedz

};
