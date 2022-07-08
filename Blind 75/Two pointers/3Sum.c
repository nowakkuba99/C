int compare(const void *a1, const void *b1) {
    const int a = *(int *)a1;
    const int b = *(int *)b1;
    if (a < b)
        return -1;
    else if (a == b)
        return 0;
    else
        return 1;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int N = 0;
    int L,R,sum,target = 0;
    int allocated = numsSize * 2;
    int **res = (int **)malloc(allocated * sizeof(int *));
    *returnSize = 0;
    if (numsSize < 3)
        return res;
        
    
    qsort(nums, numsSize, sizeof(*nums), compare);
    
    for(int i = 0; i<numsSize-2; i++)
    {
        target = 0-nums[i];
        if((i>0 && nums[i-1] != nums[i]) || i==0)
        {
            target = 0 - nums[i];
            L = i+1;
            R = numsSize - 1;
            while(L<R)
            {
                sum = target - (nums[L] + nums[R]);
                if(sum > 0)
                    L++;
                else if(sum < 0)
                    R--;
                else if(sum == 0)
                {
                    //Add solution
                    res[N] = malloc(sizeof(int) * 3);
                    res[N][0] = nums[i];
                    res[N][1] = nums[L];
                    res[N][2] = nums[R];
                    N++;
                    if (N == allocated) 
                    {
                        allocated *= 2;
                        res = (int **)realloc(res, allocated * sizeof(int *));
                    }
                    L++;
                    while(nums[L] == nums[L-1] && L<R)
                        L++;
                }
            }
        }
    }
    
    
    
    
    
    *returnSize = N;
    *returnColumnSizes = malloc(N * sizeof(int));    
    for (int i = 0; i < N; ++i)
        (*returnColumnSizes)[i] = 3;
    return res;
}