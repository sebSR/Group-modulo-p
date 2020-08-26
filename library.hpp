#ifndef library_hpp
#define library_hpp
#include <iostream>

using namespace std;

// declaration for modulo class
const int modulo_integer = 11;

class modulo{
  private:
    int rest;
  public:
    modulo();
    modulo(int n);
    int euklides(int a, int b);
    int invers();

    friend ostream & operator<<(ostream & out, modulo & k);
    friend istream & operator>>(istream & in, modulo & k);
    modulo operator+(const modulo& k);
    modulo operator-(const modulo& k);
    modulo operator-();
    modulo operator*(const modulo& k);
    modulo operator/(const modulo& k);
    modulo & operator=(const modulo& k);
    bool operator>(const modulo& k);
    bool operator<(const modulo& k);
    bool operator>=(const modulo& k);
    bool operator<=(const modulo& k);
    bool operator==(const modulo& k);
    bool operator!=(const modulo& k);
};

class exceptions{
  private:
  public:
    static const string error[2];
};

#endif
