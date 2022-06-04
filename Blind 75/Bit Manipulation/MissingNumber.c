/*
    Calculate the sum off all numbers in the array
    and then subtract it from the sum of te numbers 
    calcutated by summing all from 0 to numsSize
*/

int missingNumber(int* nums, int numsSize){
    int sum=0;
    for(int i =0; i<numsSize; i++)
    {
        sum-=nums[i];
        sum+=(i+1);
    }
    return sum;
}