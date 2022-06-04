/*
    Problem very similar to HouseRobber, but now due to
    boundary conditions 2 sums need to be calculated:
    - without first hosue (1:end)
    - without last hosue (0:end-1)
    and the result is the max
*/
#define MAX(a,b) (((a)>(b))?(a):(b))
int rob(int* nums, int numsSize){
    if(numsSize == 1)
        return nums[0];
    int max1 = pom(nums, numsSize,0,1);
    int max2 = pom(nums, numsSize,1,0);
    return MAX(max1,max2);
}


int pom(int* nums, int numsSize, int start, int end)
{
    int curr_max = 0;
    int hist_max = 0;
    int temp = 0;
    for(int i=start;i<numsSize-end;i++)
    {
        temp = MAX(nums[i] + curr_max, hist_max);
        curr_max = hist_max;
        hist_max = temp;
    }
    return hist_max;
}