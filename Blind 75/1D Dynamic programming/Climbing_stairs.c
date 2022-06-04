/*
    Number of ways to climb stairs from point n is 
    the number of ways to climb stairs n-1 and n-2 
    so the solution is just a fibbonacci sequence!

*/

int climbStairs(int n){
    unsigned int sum=0;
    unsigned int presum=0;
    if(n<=3)
        return n;
    else
    {
        presum=2;
        sum=3;
        for(unsigned int i = 3; i<n; i++)
        {
            sum+=presum;
            presum = sum - presum;
        }
        return sum;
    }
}