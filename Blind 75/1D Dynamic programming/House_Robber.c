/*
    Keeping track of max income from 2 last buildings
    Swapping current and history at each iterarion
    to reach the global max
*/
#define MAX(a,b) (((a)>(b))?(a):(b))
int rob(int* nums, int numsSize){
    int curr_max = 0;
    int hist_max = 0;
    int temp = 0;
    for(int i=0;i<numsSize;i++)
    {
        temp = MAX(nums[i] + curr_max, hist_max);
        curr_max = hist_max;
        hist_max = temp;
    }
    return hist_max;
}