#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "library.hpp"

using namespace std;


Modulo::Modulo(){
    set_rest(0);
}


Modulo::Modulo(int n){
  set_rest(n);
}


void Modulo::set_rest(int n){
  if(n >= moduloInteger){
    n = n%moduloInteger;
  }
  while(n < 0){
    n += moduloInteger;
  }
  rest = n;
}


Modulo Modulo::operator+(const Modulo &k){
    Modulo result(rest + k.rest);
    return result;
}


Modulo Modulo::operator-(const Modulo &k){
    Modulo result(rest - k.rest);
    return result;
}


Modulo Modulo::operator*(const Modulo &k){
    Modulo result(rest * k.rest);
    return result;
}


int Modulo::extendedEuclidean(int a, int b){
 int u,w,x,z,q;
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
  if(z == 1 && x < 0){
    x += b;
  }
  return x;
}


int Modulo::inverseElement(){
  return extendedEuclidean(rest, moduloInteger);
}


Modulo Modulo::operator/(const Modulo &k){
    try{
        if(k.rest != 0){
            int inverseElement;
            inverseElement = extendedEuclidean(k.rest, moduloInteger);
	          Modulo result(rest*inverseElement);
            return result;
	}
        else throw 1;
    }
    catch (int i){
        cout << exceptions::error[i] << endl;
        return 1;
    }
}


Modulo &Modulo::operator=(const Modulo &k){
    set_rest(k.rest);
    return *this;
}


bool Modulo::operator>(const Modulo& k){
    if(rest > k.rest){
      return 1;
    }
    else{
      return 0;
    }
}


bool Modulo::operator<(const Modulo& k){
    if(rest < k.rest){
     return 1;
    }
    else{
      return 0;
    }
}


bool Modulo::operator>=(const Modulo& k){
    if(rest >= k.rest){
      return 1;
    }
    else{
      return 0;
    }
}


bool Modulo::operator<=(const Modulo& k){
    if(rest <= k.rest){
      return 1;
    }
    else{
      return 0;
    }
}


bool Modulo::operator==(const Modulo& k){
    if(rest == k.rest){
      return 1;
    }
    else{
      return 0;
    }
}


bool Modulo::operator!=(const Modulo& k){
    if(rest != k.rest){
      return 1;
    }
    else{
      return 0;
    }
}


ostream &operator<<(ostream &out, Modulo &k){
    out << k.rest;
    return out;
}


istream &operator>>(istream &in, Modulo &k){
    int tmpInt;
    try{
      in >> tmpInt;
      if (!in){
        throw 0;
      }
      k.set_rest(tmpInt);
    }
    catch(int i){
      cout << exceptions::error[i] << endl;
      exit(EXIT_FAILURE);
    }

}
