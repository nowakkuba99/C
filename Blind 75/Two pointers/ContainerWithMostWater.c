#define MAX(a,b) (((a)>(b))?(a):(b))
int maxArea(int* height, int heightSize){

    int L = 0;
    int R = heightSize - 1;
    int maxWater = 0;
    
    while(L<R)
    {
        if(height[L] < height[R])
        {
            maxWater=MAX(height[L] * (R-L),maxWater);
            L++;
        }
        else
        {
            maxWater=MAX(height[R] * (R-L),maxWater);
            R--;  
        }
    }
    return maxWater;
}
//#define MIN(a,b) (((a)<(b))?(a):(b))
/*
int maxArea(int* height, int heightSize){

    int L = 0;
    int R = heightSize - 1;
    int maxWater = 0;
    
    while(L<R)
    {
        maxWater = MAX(MIN(height[L],height[R]) * (R-L),maxWater);
        if(height[L] < height[R])
            L++;
        else
            R--;
    }
    return maxWater;
}
*/