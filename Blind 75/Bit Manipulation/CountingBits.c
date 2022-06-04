/*
    First solution is slower due to counting all bits for each number
    The second one is using the concept of repearting values and is able
    to remeber 
*/
#include<stdint.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 
int* countBits(int n, int* returnSize){
    (*returnSize) = n+1;
    int* arr = calloc((*returnSize),sizeof(int));
    unsigned int i,j=0;
    
    for(i = 0; i<(n+1); i++)
    {
        for(j=0; j<32; j++)
        {
            if((i>>j) & 1 == 1)
                arr[i]=arr[i]+1;
        }
    }
    return arr;
}

*/
int* countBits(int n, int* returnSize){
    (*returnSize) = n+1;
    int* arr = calloc((*returnSize),sizeof(int));
    unsigned int power = 1;
    for(int i = 1; i<n+1; i++)
    {
        if(power * 2 == i)
            power = i;
        arr[i] = 1 + arr[i-power];
    }
    return arr;
}