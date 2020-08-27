#include <stdio.h>
#include "euler.c"


int main(){
    int input_number;
    printf("Euler's totient function\n");
    printf("Give the natural number: "); scanf("%d", &input_number);
    printf("Relatively prime numbers with %d: \n", input_number);
    printf("\n phi(n) = %d", phi(input_number));
    printf("\n");

    return 0;
}
