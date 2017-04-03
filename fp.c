#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union floatU{
    unsigned int bits;
    float theFloat;
}floatU;

void displayFloat(float f);
float makeFloat(char* f);

int main(){
    displayFloat(-5.8125);    
}
void displayFloat(float f){
    floatU a;
    a.theFloat = f;
    int index = 31;
    int k;
    printf("%f in binary is: ", f);
    for(index; index>=0; index--){
        k = a.bits >> index;
        if(k & 1){
            printf("1");
        }
        else{
            printf("0");
        }
        if(index == 31 || index == 23){
            printf(" ");
        }
    }
    printf("\n");
}
