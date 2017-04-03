#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef union intU{
    unsigned int bits;
    int theInt;
}intU;

void displayInt(int i);
int makeInt(char* i);

int main(){
    displayInt(-9);
    char* toBePrinted = "-101";
    int theThing = makeInt(toBePrinted);
    printf("%s in decimal is: %d\n", toBePrinted, theThing);
}
void displayInt(int i){
    //Create the new union
    intU a;
    a.theInt = i;

    int index = 31;
    int k;
    printf("%d in binary is: ", i);
    for(index; index>=0; index--){
        k = a.bits >> index;
        if(k & 1){
            printf("1");
        }
        else{
            printf("0");
        }
        if(index % 8 == 0){
            printf(" ");
        }
    }
    printf("\n");
}
//Expect input like "-1001" or "+101"
int makeInt(char* i){
    //Create the new union
    intU b;

    b.bits = 0;
    int length = strlen(i)-1;
    int counter = 0;
    int k;
    char c;
    for(counter; counter<length; counter++){
        c = *(i + length - counter);
        k = 1 << counter;
        if(c == '1'){
            b.bits += k; 
        }
    }
    if(*i == '-'){
        b.bits *= -1;
    }
    return b.theInt;
}
