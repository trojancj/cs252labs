#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define true 0;
#define false 1;

int stripeTotal;
int blockTotal;

//Prototypes
int isPrime(int i);
int numPrimes(int* low, int* high, int* counter);
void getBlockTotal(int min, int max);
void getStripeTotal(int min, int max);

//Main
int main(int argc, char *argv[]){
    int min = atoi(argv[1]);
    int max = atoi(argv[2]);
    omp_set_num_threads(5);

    getStripeTotal(min, max);
    //printf("Stripe total is: %d\n", stripeTotal);
    getBlockTotal(min, max);
    //printf("%d\n", blockTotal);
}

void getBlockTotal(int min, int max){
    printf("Block:\n");
    blockTotal = 0;
    int i;
    double currTime = omp_get_wtime();
    #pragma omp parallel reduction(+: blockTotal)
    {
        #pragma omp for schedule(static, ((max-min)/4))
        for(i=min; i<max; i++){
            if(isPrime(i)){
                blockTotal = blockTotal + 1;
            }
        }
        printf("Time for %d: %lf with %d found.\n", omp_get_thread_num(), omp_get_wtime()-currTime, blockTotal);
    }
    printf("Overall time: %lf with %d found.\n", omp_get_wtime()-currTime, blockTotal);
}
void getStripeTotal(int min, int max){
    printf("Stripe:\n");
    stripeTotal = 0;
    int i;
    double currTime = omp_get_wtime();
    #pragma omp parallel reduction(+: stripeTotal)
    {
        #pragma omp for schedule(static, 1) 
        for(i=min; i<max; i++){
            if(isPrime(i)){
                stripeTotal = stripeTotal + 1;
            }
            //printf("%d, %d\n", omp_get_thread_num(), i);
        }
        printf("Time for %d: %lf with %d found.\n", omp_get_thread_num(), omp_get_wtime()-currTime, stripeTotal);
    }
    printf("Overall time: %lf with %d found.\n", omp_get_wtime()-currTime, stripeTotal);
}

//Returns true if i is prime
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

//Returns the number of primes within the given range
/*int numPrimes(int* low, int* high, int* counter){
    int tracker = *low;
    int peak = *high;
    //printf("Thread number: %d. Min is: %d. Max is %d.\n", omp_get_thread_num(), *low, *high);
    for(tracker; tracker<peak; tracker++){
        if(isPrime(tracker)){
            *counter = *counter+1;
        }
    }
    return *counter;
}
*/
