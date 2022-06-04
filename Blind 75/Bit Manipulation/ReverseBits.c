/*
    Shift Get the first bit by shifting and applaying and bitwise operator
    then shift by correct number of bits
*/
#include<stdint.h>
uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;
    for (int i = 0; i<32;i++)
    {
        ret+=((n>>i)&1) <<(31-i);
    }
    return ret;
}