/* ⓒ Jakub Nowak 
Program to swap to bytes
Arguments: Num - number in which bit will be swpaed - 16 bits max
Bit_1 - First bit, Bit_2 - secnond bit to swap
Return: 1 - ok, 0 - error
*/

/*Includes*/
#include <stdio.h>
#include <math.h>
/*File includes*/

/*Functions definitions*/
int bit_swap(unsigned int* num, unsigned int bit1, unsigned int bit2);
int change_format_binary(void *voidArray, unsigned int num, unsigned int array_length);
/*Main*/
int main()
{
    //Variables
    const int size = 16;
    char binary[size];
    unsigned int number = 2055;
    for(unsigned int i =0; i<size;i++)
    {
       binary[i]=48;    //Set chars  equal to 0
    }
    //Change number format to binary
    change_format_binary(binary, number,sizeof(binary)/sizeof(binary[0]));
    printf("\nNumber %d in binary:",number);
    for(unsigned int i =0; i<size;i++)
    {
        if(i!=0 && i%4 ==0)
       {
           printf("\t");
       }
       printf("%c",binary[i]);
    }
    //Swap bits
    bit_swap(&number,1,10);
    //Change number format to binary
    change_format_binary(binary, number,sizeof(binary)/sizeof(binary[0]));
    printf("\nAfter swap:");
    printf("\nNumber %d in binary:",number);
    for(unsigned int i =0; i<size;i++)
    {
        if(i!=0 && i%4 ==0)
       {
           printf("\t");
       }
       printf("%c",binary[i]);
    }
    return 1;
}
/*Functions body*/
int bit_swap(unsigned int* num, unsigned int bit1, unsigned int bit2)
{
    //Variables
    unsigned int bit_length = 0;
    unsigned char bit1_val, bit2_val = 0;
    unsigned int xor_val=0;
    //Get the bit length
    bit_length = (int) log2(*num)+1;
    //Check if given bits to swap are valid
    if((bit1 >= bit_length) || (bit2 >= bit_length) || (bit1 == bit2))
    {
        printf("Error, Bit_length: %d",bit_length);
        return 0;   //Error
    }
    else
    {
        //Get the first bit
        bit1_val = (*num >> bit1) & 1;
        //Get the second bit
        bit2_val = (*num >> bit2) & 1;

        //Check if they are different
        xor_val=bit1_val ^ bit2_val;
        if(!xor_val)
        {
            return 1;   //End - bits have the same value
        }
        else
        {
            // Swap bits
            *num = *num ^ (xor_val << bit1 | xor_val << bit2);
            return 1;
            /* example
            number = 1010
            bit 1 = 0
            bit 2 = 1
            xor(bit1,bit2)=1
            xor_val << 1 = 0010
            xor_val << 2 = 0100
            0010 | 0101 = 0110 - number with 1 at places where bits are changed
            So if at that place was 1 it will be changed to 0 
            and if at that place was 0 it will be changed to 1
            xor(number=1010,0110)=1100
            result = 1100
            end of exaple*/
        }
    }
}
int change_format_binary(void *voidArray, unsigned int num, unsigned int array_length)
{
    //Variables
    unsigned int bit_length = 0;
    char *charArray = voidArray;
    //Get the bit length
    bit_length = (int) log2(num)+1;
    if(bit_length > array_length)
    {
        return 0;   //Error
    }
    else
    {
        for(unsigned int i = array_length-1;i>=(array_length - bit_length);i--)
        {
            charArray[i] = ((num & 1)+48);
            num=num>>1;
        }
        return 1;
    }
}