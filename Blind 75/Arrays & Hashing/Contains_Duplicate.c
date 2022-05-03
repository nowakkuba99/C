#include <stdio.h>
#include <stdbool.h>
/*
    Problem description
    -------------------
    Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
    
    Solution description
    -------------------
    1. Sort the array with build in "qsort" function. Arguments: array, arraySize, elementSize, compFunction
    2. If elements next to each other are the same -> return TRUE
    3. If after going through whole list none is the same -> return FALSE

    compFunction description
    -------------------
    Accepts to void pointers as arguments.
    Then casts them into int: *(int*)a;
    If b>a -> return -1;
    If a>b -> return 1;
    If a==b -> return 0; 

*/

//Functions definitions
int comp (const void * a, const void * b);
bool containsDuplicate(int* nums, int numsSize);

//Main
int main()
{
    const int n = 10;
    int tab[n] = {1,1,1,3,3,4,3,2,4,2};
    int tab1[n] = {10112, 123123, 214141, 312412, 5125412, 512515, 125126, 521515 ,125125 ,14134};

    bool ret = containsDuplicate(tab1, n);
    if(true == ret)
        printf("There are duplicates in the array!");
    else
        printf("There are no duplicates in the array!");
    return 0;
}

//Functions bodies
int comp (const void * a, const void * b)
{
    int _a = *(int*)a;
    int _b = *(int*)b;
    if(_a < _b) return -1;
    else if(_a == _b) return 0;
    else return 1;
}

bool containsDuplicate(int* nums, int numsSize){
  qsort(nums, numsSize, sizeof(int), comp);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i+1]) return true;
    }
    return false;
}

