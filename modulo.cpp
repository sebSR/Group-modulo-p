#include <iostream>
#include <math.h>
#include "library.hpp"

int u,w,x,z,q;      //variables for extended Euclidean algorithm

using namespace std;

modulo:: modulo(){
    rest = 0;
}

modulo:: modulo(int n){
    rest = n%p;
}

modulo modulo::operator+(const modulo& k){
    modulo result;
    if(rest+k.rest < p) result.rest = rest+k.rest;
    else result.rest = rest+k.rest-p;
    return result;
}

modulo modulo::operator-(const modulo& k){
    modulo result;
    if(rest-k.rest >= 0) result.rest = rest-k.rest;
    else result.rest = rest - k.rest + p;
    return result;
}

modulo modulo::operator-(){
    modulo result;
    if(rest > 0) result.rest=-rest + p;
    else result.rest = 0;
    return result;
}

modulo modulo::operator*(const modulo& k){
    modulo result;
    result.rest = (rest * k.rest)%p;
    return result;
}

int modulo:: euklides(int a, int b){
 u = 1; w = a;
 x = 0; z = b;
  while(w){
    if(w < z){
      q = u; u = x; x = q;
      q = w; w = z; z = q;
    }
    q = w / z;
    u -= q * x;
    w -= q * z;
  }
  if(z == 1){
    if(x < 0) x += b;
  }
  return x;
}

modulo modulo::operator/(const modulo& k){
    modulo result;
    try {
        if(k.rest != 0){
            euklides(k.rest,p);
            result.rest = (rest*x)%p;
            return result;}
        else throw 1;}
    catch (int i){cout << exceptions::error[i] << endl; return 1;}
}

modulo &modulo:: operator+=(const modulo& k){
    rest += k.rest;
    rest = rest%p;
    return * this;
}

modulo &modulo:: operator-=(const modulo& k){
    if( rest - k.rest >= 0 ) rest = rest - k.rest;
    else rest = rest - k.rest + p;
    return * this;
}

modulo &modulo::operator*=(const modulo& k){
    rest = (rest * k.rest)%p;
    return *this;
}

modulo &modulo::operator/=(const modulo& k){
    try{
        if (k.rest != 0){
            euklides(k.rest,p);
            rest = (rest * x)%p;
            return *this;}
        else throw 1;}
    catch (int i){ cout << exceptions::error[i] << endl; return *this;}
}

modulo &modulo::operator=(const modulo& k){
    rest = k.rest;
    return *this;
}

bool modulo::operator>(const modulo& k){
    if( rest > k.rest ) return 1;
    else return 0;
}

bool modulo::operator<(const modulo& k){
    if( rest < k.rest ) return 1;
    else return 0;
}

bool modulo::operator>=(const modulo& k){
    if( rest >= k.rest ) return 1;
    else return 0;
}

bool modulo::operator<=(const modulo& k){
    if( rest <= k.rest ) return 1;
    else return 0;
}

bool modulo::operator==(const modulo& k){
    if( rest == k.rest ) return 1;
    else return 0;
}

bool modulo::operator!=(const modulo& k){
    if( rest != k.rest ) return 1;
    else return 0;
}

ostream &operator<<(ostream & out, modulo & k){
    out << k.rest << endl;
    return out;
}

istream &operator>>(istream & in, modulo & k){
    in >> k.rest;
    try { if (k.rest < p && k.rest >= 0) return in;
          else throw 0;}
    catch (int i) { cout << exceptions::error[i] << endl; return in;}
}
