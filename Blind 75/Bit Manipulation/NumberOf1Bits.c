/*
    Calucluate the number of 1 bits by using bit shift and 
    bitwise and operation with least importnant bit
*/
#include <stdint.h>

int hammingWeight(uint32_t n) {
    unsigned int sum = 0;
    for(unsigned int i = 0; i<32; i++)
        sum+=(n>>i)&1;
    return sum;
}