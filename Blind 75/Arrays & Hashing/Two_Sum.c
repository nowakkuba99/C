#include <stdio.h>
#include <stdlib.h>

/*
    Problem description
    -------------------
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    Solution description
    -------------------
    1. Calculate difference beetween target and current number
    2. Check if past number equals difference

*/

//Functions delaration 
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
//Main
int main()
{
    int arr[4]={0,4,3,0};
    int a = 2;
    int* size = &a;
    int* arr2 = twoSum(arr,4,0,size);
    for(int i=0;i<sizeof(arr2)/sizeof(int);i++)
    {
        printf("%d", arr2[i]);
    }
    free(arr2);
    return 0;
}

//Function body
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    (*returnSize) = 2;
    int* arr = malloc((*returnSize) * sizeof(int));
    int diff=0,i=0,j=0;
    for(i=1;i<=numsSize;i++)
    {
        diff = target - nums[i];
        for(j=0;j<i;j++)
        {
            if(nums[j] == diff)
            {
                arr[0]=j;
                arr[1]=i;
                return arr;
            }
        }
    }
    return arr;
}