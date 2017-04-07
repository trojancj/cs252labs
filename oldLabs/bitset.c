#include <stdio.h>
#include <stdlib.h>

typedef unsigned short bitSet;

bitSet makeBitSet();                    //Create new bitset
void displayBitSet(bitSet bs);          //Displays the 16 bits of the bitset to the screen
void setBit(bitSet* bs, int index);     //Sets bit 'index' of the bitset to 1
void clearBit(bitSet* bs, int index);   //Sets bit 'index' of the bitset to 0
int bitValue(bitSet bs, int index);     //Returns the value of the bit at 'index'
void flipBits(bitSet* bs);              //Flips all the bits in a bitset

int main(){
    bitSet supreme = makeBitSet();
    displayBitSet(supreme);
    clearBit(&supreme, 15);
    displayBitSet(supreme);
}

bitSet makeBitSet(){
    bitSet* a = (bitSet*)malloc(1 * sizeof(bitSet));
    *a = 29;    
    return *a;
}

void displayBitSet(bitSet bs){
    int i = 15;
    int k;
    printf("%d in binary is: \n", bs);
    for(i; i >= 0; i--){
        k = bs >> i;
        if(k & 1){
            printf("1");
        }
        else{
            printf("0");
        }
    }
    printf("\n");
}
void setBit(bitSet* bs, int index){
    *bs = *bs | (1 << (15 - index));
}
void clearBit(bitSet* bs, int index){
    *bs = *bs & ~(1 << (15 - index));
}
int bitValue(bitSet bs, int index){
    int k = bs >> (15 - index);
    return (k & 1);
}
void flipBits(bitSet* bs){
    *bs = ~(*bs);
}
