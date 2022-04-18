/* ⓒ Jakub Nowak 
Program to calculate factorial
Arguments: Number - to calculate from, Result - place where to assign result
Return: None
*/

/*Includes*/
#include <stdio.h>
/*File includes*/

/*Functions definitions*/
void factorial(int num, unsigned long* result);
/*Main*/
int main()
{
    int number = 10;
    unsigned long number_factorial = 0;
    factorial(number,&number_factorial);
    printf("Factorial of %d is %lu",number,number_factorial);
    return 1;
}
/*Functions body*/
void factorial(int num, unsigned long* result)
{
    // Set temorary result to 1
    int temp_res = 1;
    // Main loop
    for(int i = num;i>1;i--)
    {
        temp_res *= i; 
    }
    // Assign result
    *result = temp_res;
}