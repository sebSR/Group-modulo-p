#include <iostream>
#include <math.h>
#include "library.hpp"

//variables for extended Euclidean algorithm
int u,w,x,z,q;
using namespace std;


modulo:: modulo(){
    rest = 0;
}


modulo:: modulo(int n){
  while(n >= modulo_integer){
    n = n%modulo_integer;
  }
  cout << rest;
  rest = n;
}


modulo modulo::operator+(const modulo& k){
    modulo result;
    if(rest+k.rest < modulo_integer){
      result.rest = rest + k.rest;
    }
    else{
      result.rest = rest + k.rest - modulo_integer;
    }
    return result;
}


modulo modulo::operator-(const modulo& k){
    modulo result;
    if(rest-k.rest >= 0){
      result.rest = rest-k.rest;
    }
    else{
      result.rest = rest - k.rest + modulo_integer;
    }
    return result;
}


modulo modulo::operator*(const modulo& k){
    modulo result;
    result.rest = (rest * k.rest)%modulo_integer;
    return result;
}


// return inverse element to a in Z(b)
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


int modulo:: invers(){
 u = 1; w = rest;
 x = 0; z = modulo_integer;
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
    if(x < 0){
      x += modulo_integer;
    }
  }
  return x;
}


modulo modulo::operator/(const modulo& k){
    modulo result;
    try {
        if(k.rest != 0){
            euklides(k.rest, modulo_integer);
            result.rest = (rest*x)%modulo_integer;
            return result;}
        else throw 1;}
    catch (int i){cout << exceptions::error[i] << endl; return 1;}
}


modulo &modulo::operator=(const modulo& k){
    rest = k.rest;
    return *this;
}


bool modulo::operator>(const modulo& k){
    if(rest > k.rest){
      return 1;
    }
    else return 0;
}


bool modulo::operator<(const modulo& k){
    if(rest < k.rest){
     return 1;
    }
    else{
      return 0;
    }
}


bool modulo::operator>=(const modulo& k){
    if(rest >= k.rest){
      return 1;
    }
    else{
      return 0;
    }
}


bool modulo::operator<=(const modulo& k){
    if(rest <= k.rest){
      return 1;
    }
    else{
      return 0;
    }
}


bool modulo::operator==(const modulo& k){
    if( rest == k.rest ) return 1;
    else return 0;
}


bool modulo::operator!=(const modulo& k){
    if(rest != k.rest){
      return 1;
    }
    else{
      return 0;
    }
}


ostream &operator<<(ostream &out, modulo &k){
    out << k.rest;
    return out;
}

istream &operator>>(istream &in, modulo &k){
    in >> k.rest;
    while(k.rest >= modulo_integer){
      k.rest = k.rest%modulo_integer;
    }
    try{
      if (k.rest < modulo_integer && k.rest >= 0){
         return in;
      }
      else{
        throw 0;
      }
    }
    catch (int i){
      cout << exceptions::error[i] << endl;
      return in;
    }
}
