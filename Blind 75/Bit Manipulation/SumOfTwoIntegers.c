/*
    Not the most subtale solution but workng and quite efficient
    The idea is to perform only 2 operations: 
    - Bitwise adding
    - Bitwise subtracting
    So if:
     a>0 and b>0 -> add(a,b)
     a<0 and b<0 -> -add(a,b)
     a>0 and b<0 
        |a| > |b| -> subtract(a,b)
        |a| < |b| -> -subtract(b,a)
     a<0 and b>0 
        |a| > |b| -> -subtract(a,b)
        |a| < |b| -> subtract(b,a)
    

*/

#define MAX(a,b) (((a)>(b))?(a):(b))
int add(a,b)
{
    int mem = 0;
    int res = 0;
    int x = 0;
    int y = 0;
    for(int i=0;i<11;i++)
    {
        x = (a>>i)&1;
        y = (b>>i)&1;
        if(x&y)
        {
            if(mem)
                res += 1<<i;
            mem = 1;
        }
        else if(x|y)
        {
            if(!mem)
                res+= 1<<i;
        }
        else if(!(x&y))
        {
             if(mem)
             {
                 res+= 1<<i;
                 mem=0;
             }
        }    
        
    }
    return res;
}
int reverse(int a, int b)
{
    int max=0;
    int result = 0;
    int i =0;
    for(i=11;i>0;i--)
    {
        if((a>>i)&1 || (b>>i)&1)
        {
            max = i;
            break;
        }
    }
    for(i=0;i<=max;i++)
    {
        result+=(~(b>>i)&1)<<i;
    }
    return result;
}

int getSum(int a, int b){
    int result = 0;
    int a_org=a;;
    int b_org=b;
    if(a >=0 && b>=0)
    {
        result = add(a,b);
    }
    else if(a>0 && b<0)
    {
        b_org*=-1;
        b*=-1;
        if(b<a)
        {
            b = reverse(a,b);
            result = add(a,b);
            if(result > a_org+b_org)
            {
                for(int i=11;i>0;i--)
                {
                    if((result>>i)&1)
                    {
                        result-=1<<i;
                        result = add(result,1);
                        break;
                    }
                }
            }
        }
        else
        {
            b = reverse(a,b);
            result = add(a,b);
            if(result > a_org+b_org)
            {
                for(int i=11;i>0;i--)
                {
                    if((result>>i)&1)
                    {
                        result-=1<<i;
                        result = add(result,1);
                        break;
                    }
                }
            }
            result = - reverse(MAX(a_org,b_org),result);
        }
    }
    else if(a<0 && b>0)
    {
        a_org*=-1;
        a*=-1;
        if(b>a)
        {
            a = reverse(b,a);
            result = add(a,b);
            if(result > a_org+b_org)
            {
                for(int i=11;i>0;i--)
                {
                    if((result>>i)&1)
                    {
                        result-=1<<i;
                        result = add(result,1);
                        break;
                    }
                }
            }
        }
        else
        {
            a = reverse(b,a);
            result = add(a,b);
            if(result > a_org+b_org)
            {
                for(int i=11;i>0;i--)
                {
                    if((result>>i)&1)
                    {
                        result-=1<<i;
                        result = add(result,1);
                        break;
                    }
                }
            }
            result = - reverse(MAX(a_org,b_org),result);
        }
    }
    else if(a<=0 && b<=0)
    {
        a*=-1;
        b*=-1;
        result=-add(a,b);
    }
    return result;
}