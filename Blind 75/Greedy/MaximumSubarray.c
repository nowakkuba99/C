/*
    Start with max set to the first number
    If after adding next number result is negative save max value until that time and reset current variable
    It is done like so since negative value is a downside so we can discard it and start over 
    If we found greater sum we change max variable if not we remeber last max
*/
#define MAX(a,b) (((a)>(b)) ? (a):(b))
int maxSubArray(int* nums, int numsSize){
    int curr = 0;
    int max = nums[0];
    for(int i=0;i<numsSize;i++)
    {
        curr += nums[i];
        max = MAX(max,curr);
        if(curr < 0)
            curr = 0;
    }
    return max;
}