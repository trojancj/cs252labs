#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> // compile with -pthread flag

#define true 0;
#define false 1;

int total;
pthread_mutex_t lock;

int isPrime(int i);
int numPrimes(int* low, int* high, int* counter);

void* run(void* parm){
    int* p = (int*)parm;
    int start = (((p[1] - p[0]) / p[3]) * p[2]) + p[0];
    int end = (((p[1] - p[0]) / p[3]) * (p[2] + 1)) + p[0];
    int counter = 0;
    pthread_mutex_lock(&lock);
    total = total + numPrimes(&start, &end, &counter);
    pthread_mutex_unlock(&lock);
}

int main(){
    pthread_mutex_init(&lock, NULL);
    int min = 10;
    int max = 100;
    int counter = 0;
    int numThreads = 4;
    pthread_t ids[numThreads];
    int threadNum = 0;
    total = 0;
    for(threadNum; threadNum < numThreads; threadNum++){
        int* p = (int*)malloc (4 * sizeof(int));
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
    printf("Total is %d\n", total);
    
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
