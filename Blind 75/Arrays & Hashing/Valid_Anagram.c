#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
/*
    Problem description
    -------------------
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.

    Solution description
    -------------------
    1. Sort arrays with qsort
    2. Chck if all elements are the same

*/
//Functions declaration
int comp (const void * a, const void * b);
bool isAnagram(char * s, char * t);

//Main
int main()
{
    char str[] = "mamutatumam";
    char str1[] = "mamtumamuta";
    bool ret = isAnagram(str, str1);
    if(true == ret)
        printf("Anagram!");
    else
        printf("Not anagram!");
    return 1;
}
//Function bodies
int comp (const void * a, const void * b)
{
    char _a = *(char*)a;
    char _b = *(char*)b;
    if(_a < _b) return -1;
    else if(_a == _b) return 0;
    else return 1;
}

bool isAnagram(char * s, char * t){
    int s_size = strlen(s);
    int t_size = strlen(t);
    if(s_size != t_size)
        return false;
    //Sort the arrays
    qsort(s, s_size, sizeof(char), comp);
    qsort(t, t_size, sizeof(char), comp);
    for(unsigned int i =0; i<s_size; i++)
    {
        if(s[i] != t[i])
            return false;
    }
    return true;
}