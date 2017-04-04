#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> // compile with -pthread flag

void* foo(void* parm){ //void* is an array of stuff
    int* pm = (int*)parm; //Downcast from void* to int*
    printf("Hello %d\n", pm[0]); 
    
}

int main() {
    int n = 10;

    pthread_t ids[n];

    int i;

    for (i=0; i<n; i++){
        //int p[3];
        int* p = (int*)malloc(3*sizeof(int));

        pthread_t t;
        p[0] = i;
        p[1] = 5;
        p[2] = 8;

        pthread_create(&(ids[i]), NULL, foo, (void*)p); //(thread id, attributes, function, args)
                                                        //Upcast from int* to void*
    }
    for(i=0; i<n; i++){
        pthread_join(ids[i], NULL);
    }

    printf("Done\n");
}
