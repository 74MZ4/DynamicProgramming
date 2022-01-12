#include <stdlib.h>
#include <stdio.h>
#include <string.h>

double fib(int x, double *memo) {
    if (x == 0) return 0;
    if (x <= 2) return 1;
    if (memo[x-1] == 0) memo[x-1] =  fib(x - 1, memo) + fib(x - 2, memo);
    return memo[x-1];
}

void main(int argc, char **argv) {

    if (argc == 2) {

        char buffer[50];
        strcpy(buffer, *(argv+1));
        int x = atoi(buffer);

        double *memo = malloc(sizeof(double) * x);
        for (int i=0; i<x; i++) {
            memo[i] = 0;
        }
        printf("fibonacci (%d)= %.f", x, fib(x, memo)); // 12586269025
    }
    else {
        printf("function takes 1 argument as number");
    }
}