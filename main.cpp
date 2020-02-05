#include <iostream>
#include <math.h>
#include "library.hpp"

using namespace std;

int main(){
    modulo k,l,m;   // objects of class Modulo
    cout << "Class, ModuloP for P = 15 -> {0,1,...,14}"  << endl << endl;
    cout << "Give a value for first object of class ModuloP k = ";  // loading variables
    cin >> k;
    cout << "Give a value for second object of class ModuloP l = ";
    cin >> l;
    cout << endl;

    if ( k == l) cout << "k = l " << endl;
        else if ( k != l) cout << "k != l " << endl;
    if (k < l) cout << "k < l " << endl;
        else if (k > l) cout << "k > l " << endl;
    cout << endl;

    m = k + l;
    cout << "k+l = " << m << endl;
    m = k - l;
    cout << "k-l = " << m << endl;
    m = k * l;
    cout << "k*l = " << m << endl;
    m = k/l;
    cout << "k/l = " << m << endl;
    m = k += l;
    cout << "k+=l = " << m << endl;
    m = k-=l;
    cout << "k-=l = " << m << endl;
    m = k *= l ;
    cout << "k*=l = " << m << endl;
    m = k /= l;
    cout << "k/l = " << m << endl;

    return 0;
}
