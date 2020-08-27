#include <math.h>
#include <stdio.h>
#include <stdlib.h>

 // Euklides
int nwd(int a, int b){
    int rest;
    while(b>0){
        rest = a%b;
        a = b;
        b = rest;
    }
    return a;
}
