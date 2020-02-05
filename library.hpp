#ifndef library_hpp
#define library_hpp
#include <iostream>

using namespace std;

const int p = 13;//deklaracja p, mo�liwo�� zmiany dla cia�a inne liczby pierwszej

class modulo{
  private:
    int rest;
  public:
    modulo();
    modulo(int n);
    int euklides(int a, int b);//wyznacza element odwrotny

    friend ostream & operator<<(ostream & out, modulo & k);
    friend istream & operator>>(istream & in, modulo & k);
    modulo operator+(const modulo& k);
    modulo operator-(const modulo& k);
    modulo operator-();
    modulo operator*(const modulo& k);
    modulo operator/(const modulo& k);
    modulo & operator+=(const modulo& k);
    modulo & operator-=(const modulo& k);
    modulo & operator*=(const modulo& k);
    modulo & operator/=(const modulo& k);
    modulo & operator=(const modulo& k);
    bool operator>(const modulo& k);
    bool operator<(const modulo& k);
    bool operator>=(const modulo& k);
    bool operator<=(const modulo& k);
    bool operator==(const modulo& k);
    bool operator!=(const modulo& k);
};

class exceptions{//klasa wyrzuca wyj�tki dla �le wpr warto�ci i dzielenia przez 0
  private:
  public:
    static const string error[2];
};

#endif




