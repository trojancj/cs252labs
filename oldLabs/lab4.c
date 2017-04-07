#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binToDec(char* bin);
char* decToBin(int dec);

int main(){

    char* a = decToBin(5);
    printf("%s\n", a);

    char *pp = "1001";
    int aaa = binToDec(pp);
    printf("%d\n", aaa);
}

char* decToBin(int dec){
    int a[50];
    int i = 0;
    int length = 0;

    char *c = (char*)malloc(10 * sizeof(char));

    while (dec>0){
        c[i] = (dec%2)+'0';
        dec = dec/2;
        i++;
    }

    return c;
}
int binToDec(char* bin){
    int num = atoi(bin);
    int bin_val;
    int dec_val = 0;
    int base = 1;
    int rem;

    while(num>0){
        rem = num % 10;
        dec_val = dec_val + rem * base;
        num = num / 10;
        base = base * 2;
    }

    return dec_val;
}
