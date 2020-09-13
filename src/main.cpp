#include <iostream>
#include <math.h>
#include "library.hpp"


void division(Modulo &one, Modulo &two){
    try{
	std::cout << one << " / " << two << " = " << one / two << std::endl;
    }catch(int i){
	std::cout << Modulo::error[i] << std::endl;
    }	
}


int main(){
    Modulo firstObject, secondObject;
    std::cout << "Class ModuloP for P = 11 -> {0,1,...,10}"  << std::endl << std::endl;
    std::cout << "Give a value for firstObject of class ModuloP: ";
    std::cin >> firstObject;
    std::cout << "Give a value for secondObject of class ModuloP: ";
    std::cin >> secondObject;
    std::cout << std::endl;
    std::cout << "Inverse element to the "<< firstObject <<": " << firstObject.inverseElement();
    std::cout << std::endl << std::endl;
    std::cout << "Inverse element to the "<< secondObject <<": " << secondObject.inverseElement();
    std::cout << std::endl << std::endl;

    std::cout << "Basic operators in class ModuloP:" << std::endl;
    std::cout << firstObject << " + " << secondObject << " = " << firstObject + secondObject << std::endl;

    std::cout << firstObject << " - " << secondObject << " = " << firstObject - secondObject << std::endl;

    std::cout << firstObject << " * " <<  secondObject << " = " << firstObject * secondObject << std::endl;

    division(firstObject, secondObject);

    return 0;
}
