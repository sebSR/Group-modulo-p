#ifndef library_hpp
#define library_hpp
#include <iostream>

using namespace std;

const int moduloInteger = 11;


class Modulo{
  private:
    int rest;
  public:
    Modulo();
    Modulo(int n);

    void set_rest(int n);

    int extendedEuclidean(int a, int b);
    int inverseElement();

    friend ostream & operator<<(ostream &out, Modulo &k);
    friend istream & operator>>(istream &in, Modulo &k);
    Modulo operator+(const Modulo &k);
    Modulo operator-(const Modulo &k);
    Modulo operator-();
    Modulo operator*(const Modulo &k);
    Modulo operator/(const Modulo &k);
    Modulo & operator=(const Modulo &k);
    bool operator>(const Modulo &k);
    bool operator<(const Modulo &k);
    bool operator>=(const Modulo &k);
    bool operator<=(const Modulo &k);
    bool operator==(const Modulo &k);
    bool operator!=(const Modulo &k);
};

class exceptions{
  private:
  public:
    static const string error[2];
};

#endif
