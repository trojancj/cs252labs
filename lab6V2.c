#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> // compile with -pthread flag

#define true 0;
#define false 1;

int isPrime(int i);
int numPrimes(int* low, int* high, int* counter);

void* run(void* parm){
    //Find start
    int* p = (int*)parm;
    //printf("%d\n", p[2]);
    int start = (((p[1] - p[0]) / p[3]) * p[2]) + p[0];
    //Find end
    int end = (((p[1] - p[0]) / p[3]) * (p[2] + 1)) + p[0];
    //Call numPrimes
    int counter = 0;
    p[4+p[2]] = numPrimes(&start, &end, &counter);
    //Set the total number of primes to array slot
}

int main(){
    int min = 1000;
    int max = 1000000;
    int counter = 0;
    int numThreads = 4;
    pthread_t ids[numThreads];
    int threadNum = 0;
    for(threadNum; threadNum < numThreads; threadNum++){
        int* p = (int*)malloc((4+numThreads) * sizeof(int));
        p[0] = min;
        p[1] = max;
        p[2] = threadNum;
        p[3] = numThreads;

        pthread_create(&(ids[threadNum]), NULL, run, (void*)p);
    }
    int joinBack = 0;
    for(joinBack; joinBack < numThreads; joinBack++){
        pthread_join(ids[joinBack], NULL);
    }
    //Add stuff back together :)
    //Problem is the scope of p
    int j = 4;
    int total = 0;
    for(j; j<8; j++){
        total = total + p[j];
    }
    printf("Total is %d\n", total);
    printf("Done\n");
    
}

int isPrime(int i){
    int j = 2;
    while(j<i){
        if(i%j == 0){
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
