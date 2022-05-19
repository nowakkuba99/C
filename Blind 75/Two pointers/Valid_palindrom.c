#include<stdio.h>
#include<stdbool.h>

bool isPalindrome(char * s){
    unsigned int l=0;   //Left most character
    unsigned int r=strlen(s)-1; //Right most character
    while(1)
    {
        if(s[l] >= 65 && s[l] <= 90)
            s[l] += 32;
            
        if((s[l] < 48)||(s[l] > 57 && s[l] < 97) || s[l] > 122)
        {
            if(l<r)
                l++;
            else
                break;
        }
        else
        {
            if(s[r] >= 65 && s[r] <= 90)
                s[r] += 32;

            if((s[r] < 48)||(s[r] > 57 && s[r] < 97) || s[r] > 122)
            {
                if(l<r)
                    r--;
                else
                    break;
            }
            else
            {
                if(s[l] != s[r])
                    return false;
                else if(l<r)
                {
                    l++;
                    r--;
                }
                else
                    break;
            }
        }
    }
    return true;
}