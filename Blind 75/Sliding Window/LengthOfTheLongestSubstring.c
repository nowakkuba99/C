#include <stdint.h>
#include <stdlib.h>

#define MAX(a,b) (((a)>(b))?(a):(b))
void shiftLeft (char *str,int shiftLength)
{
    for(int j=0;j<shiftLength;j++)
    {   
        int i =0;   
        while(str[i]!='\0') //character \0 is the last character in the string
        {
            str[i] = str[i+1];
            i++;
        }
    }
}
int lengthOfLongestSubstring(char * s){
    if(strlen(s) <2)
        return strlen(s);
    int max_len=0;
    int shift = 0;
    int index = 0;
    char *currString;
    size_t length;
    length = strlen(s);
    currString = (char *)calloc(length, sizeof(char));
    char set[128];
    for(int i =0; i<127;i++)
    {
        set[i] = 0;
    }
    for(int i = 0; i<length; i++)
    {
        if(set[s[i]] == 0)
        {
            // Not present in string
            currString[index] = s[i];
            set[s[i]] = 1;
            index++;
        }
        else
        {
            // Already in string
            max_len = MAX(index,max_len);
            if(i!=length-1)
            {       
                shift=1;
                while(s[i] != currString[shift-1])
                {
                    set[currString[shift-1]]=0;
                    shift++;
                }
                shiftLeft(currString,shift);
                index = strlen(currString);
                currString[index] = s[i];
                index++;
                set[s[i]] = 1;
            }
        } 
    }
    max_len = MAX(index,max_len);
    return max_len;
}