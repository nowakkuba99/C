#include <stdint.h>
#include <stdlib.h>
char * longestPalindrome(char * s){
    char *currString;
    size_t length;
    length = 2*strlen(s);
    currString = (char *)calloc(length, sizeof(char));
    size_t resLen=0;
    int l,r;
    for(int i = 0; i<strlen(s); i++)
    {
        //Nieparzysta długość
        l = i;
        r = i;
        while(l>= 0 && r<strlen(s) && s[l] == s[r])
        {
            if((r-l+1) > resLen)
            {
                resLen = r-l+1;
                for(int j = 0; j<resLen;j++)
                    currString[j]=s[l+j];
                currString[r+1]='\0';
            }
            l--;
            r++;
        }
        //Parzysta długość
        l = i;
        r = i+1;
        while(l>= 0 && r<strlen(s) && s[l] == s[r])
        {
            if((r-l+1) > resLen)
            {
                resLen = r-l+1;
                for(int j = 0; j<resLen;j++)
                    currString[j]=s[l+j];
                currString[r+1]='\0';
            }
            l--;
            r++;
        }
    }
    return currString;
}