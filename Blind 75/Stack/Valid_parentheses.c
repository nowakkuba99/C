#include <stdio.h>
#include <stdbool.h>

bool isValid(char * s){
    int len = strlen(s);  //Length of string
    char *stack = malloc( sizeof(char) * ( len + 1 ) );
    if(len == 1)
    {
        free(stack);
        return false;   //If length == 1 ->false
    }
    unsigned int j=0;
    for(unsigned int i=0;i<len;i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            //Opening bracket
            if(i>0)
                j++;  //Keep track of the top
            stack[j] = s[i];  //Add to stack

        }
        else
        {
            //Closing bracket
            if(stack[j] == s[i]-1 || stack[j] == s[i]-2)
            {
                //Matches with the last one
                stack[j] = ' ';
                if(j>0)
                    j--;
            }
            else
            {
                //Does not match
                free(stack);
                return false;
            }
        }
    }
    
    if(j>0 || stack[0] != ' ')
    {
        free(stack);
        return false;
    }
    free(stack);
    return true;
}