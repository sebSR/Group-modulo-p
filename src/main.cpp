#include <iostream>
#include <math.h>
#include "library.hpp"

using namespace std;

int main(){
    Modulo firstObject, secondObject, tmpObject;
    cout << "Class ModuloP for P = 11 -> {0,1,...,10}"  << endl << endl;
    cout << "Give a value for firstObject of class ModuloP: ";
    cin >> firstObject;
    cout << "Give a value for secondObject of class ModuloP: ";
    cin >> secondObject;
    cout << endl;
    cout << "Inverse element to the "<< firstObject <<": " << firstObject.inverseElement();
    cout << endl << endl;
    cout << "Inverse element to the "<< secondObject <<": " << secondObject.inverseElement();
    cout << endl << endl;

    cout << "Basic operators in class ModuloP:" << endl;
    tmpObject = firstObject + secondObject;
    cout << firstObject << " + " << secondObject << " = " << tmpObject << endl;

    tmpObject = firstObject - secondObject;
    cout << firstObject << " - " << secondObject << " = " << tmpObject << endl;

    tmpObject = firstObject * secondObject;
    cout << firstObject << " * " <<  secondObject << " = " << tmpObject << endl;

    tmpObject = firstObject / secondObject;
    cout << firstObject << " / " << secondObject << " = " << tmpObject << endl;

    return 0;
}
