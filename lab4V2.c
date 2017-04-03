#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char* decToBase(int baseVal, int dec);
int baseToDec(int origBaseVal, char* bin);

int main(){

    char* a = decToBase(8, 50);
    printf("50 in base 8 is: %s\n", a);

    char *pp = "7e";
    int aaa = baseToDec(16, pp);
    printf("7e in base 16 is: %d\n", aaa);
}

//This is all done
char* decToBase(int baseVal, int dec){
    int i = 0;

    char *c = (char*)malloc(10 * sizeof(char));

    while (dec>0){
        c[i] = (dec%baseVal)+'0';
        dec = dec/baseVal;
        i++;
    }

    //This here reverses the array
    int start = 0;
    int end = i-1;
    char temp;
    while(start < end){
        temp = c[start];
        c[start] = c[end];
        c[end] = temp;
        start++;
        end--;
    }

    return c;
}

int baseToDec(int origBaseVal, char* bin){
    int i;
    int j = 0;
    int total = 0;
    int a;
    for(i=strlen(bin)-1;i>=0;i--){
        if(bin[i]<'a'){
            a = bin[i] - '0';
        }
        else{
            a = bin[i] - 'W';
        }
        total = total + a * (pow(origBaseVal, j));
        j++;
    }
    return total;
}

