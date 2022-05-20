#define MAX(x,y) (((x)>(y))?(x):(y))

int maxProfit(int* prices, int pricesSize){
    unsigned int low=0;
    unsigned int high=0;
    unsigned int i = 0;
    unsigned int last_max=0;
    for(i=1;i<pricesSize;i++)
    {
        if(prices[i] < prices[low])
        {
            if(prices[high] - prices[low] > last_max)
                last_max = prices[high] - prices[low];
            low = i;
            high = i;
        }
        if(prices[i] > prices[high])
            high = i;
    }
    return MAX(prices[high] - prices[low],last_max);
}