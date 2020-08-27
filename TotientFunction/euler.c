#include <math.h>
#include <stdio.h>
#include "nwd.c"

//Euler's totient function
int phi(int natural_number){

    if(natural_number == 1){
        return 1;
    }

    int counter = 0;
    for(int i=1; i<natural_number; i++){
        if(nwd(i, natural_number)==1){
            printf("%d ", i);
            counter++;
        }
    }

    return counter;
}
