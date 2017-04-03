#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> // compile with -pthread flag

#define true 0;
#define false 1;

int isPrime(int i);
int numPrimes(int low, int high);

int main(){
    printf("%d\n", numPrimes(10, 100));    
    
}
//true is 0 and false is 1
int isPrime(int i){
    int j = 2;
    for(j; j<i; j++){
        if(i%j == 0){
            return true;
        }
        j = j+1;
    }
    return false;
}

int numPrimes(int low, int high){
    int counter = 0;
    for(low; low<high; low++){
        if(isPrime(low)){
            counter = counter+1;
        }
    }
    return counter;
}
