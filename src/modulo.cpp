#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "library.hpp"


const std::string Modulo::error[] = {"It's not int type.", "Divided by '0' !"};


Modulo::Modulo(){
    set_rest(0);
}


Modulo::Modulo(int n){
  set_rest(n);
}


Modulo::~Modulo() = default;


void Modulo::set_rest(int n) noexcept{
  if(n >= moduloInteger){
    n = n%moduloInteger;
  }
  while(n < 0){
    n += moduloInteger;
  }
  this -> rest = n;
}


int Modulo::extendedEuclidean(int a, int b) noexcept{
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


int Modulo::inverseElement() noexcept{
  return extendedEuclidean(rest, moduloInteger);
}


std::ostream &operator<<(std::ostream &out, Modulo k) noexcept{
   out << k.rest;
   return out;
}


std::istream &operator>>(std::istream &in, Modulo &k) noexcept{
    int tmpInt;
    in >> tmpInt;
    if (!in){
	std::cout << Modulo::error[0] << std::endl;
        exit(EXIT_FAILURE);
    }
    k.set_rest(tmpInt);
}


Modulo Modulo::operator++() noexcept{
    set_rest(rest + 1);
    return *this;
}


Modulo Modulo::operator--() noexcept{
    set_rest(rest - 1);
    return *this;
}


Modulo Modulo::operator+(const Modulo &k) noexcept{
    Modulo result(rest + k.rest);
    return result;
}


Modulo Modulo::operator-(const Modulo &k) noexcept{
    Modulo result(rest - k.rest);
    return result;
}


Modulo Modulo::operator*(const Modulo &k) noexcept{
    Modulo result(rest * k.rest);
    return result;
}


Modulo Modulo::operator/(const Modulo &k) noexcept(false){
    if (k.rest != 0){
        int inverseElement;
        inverseElement = extendedEuclidean(k.rest, moduloInteger);
        Modulo result(rest*inverseElement);
        return result;
     }
     else{
	throw 1;
     }
}


Modulo &Modulo::operator=(const Modulo &k) noexcept{
    set_rest(k.rest);
    return *this;
}


bool Modulo::operator>(const Modulo& k) noexcept{
    if(rest > k.rest){
      return 1;
    }
    else{
      return 0;
    }
}


bool Modulo::operator<(const Modulo& k) noexcept{
    if(rest < k.rest){
     return 1;
    }
    else{
      return 0;
    }
}


bool Modulo::operator>=(const Modulo& k) noexcept{
    if(rest >= k.rest){
      return 1;
    }
    else{
      return 0;
    }
}


bool Modulo::operator<=(const Modulo& k) noexcept{
    if(rest <= k.rest){
      return 1;
    }
    else{
      return 0;
    }
}


bool Modulo::operator==(const Modulo& k) noexcept{
    if(rest == k.rest){
      return 1;
    }
    else{
      return 0;
    }
}


bool Modulo::operator!=(const Modulo& k) noexcept{
    if(rest != k.rest){
      return 1;
    }
    else{
      return 0;
    }
}
