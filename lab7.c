#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define true 0;
#define false 1;

int isPrime(int i);
int numPrimes(int* low, int* high, int* counter);

int main(){
    int min = 10;
    int max = 100;
    int counter = 0;
    printf("%d\n", numPrimes(&min, &max, &counter));
}

int isPrime(int i){
    int j = 2;
    while(j<i){
        if(i%j==0){
            return true;
        }
        j = j+1;
    }
    return false;
}
int numPrimes(int* low, int* high, int* counter){
    int tracker = *low;
    int peak = *high;
    for(tracker; tracker<peak; tracker++){
        if(isPrime(tracker)){
            *counter = *counter+1;
        }
    }
    return *counter;
}
