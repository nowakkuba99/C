/* ⓒ Jakub Nowak 
Program to display fibonacii sequence with recursive method
Arguments: Amount of numbers to display
Return: -
*/

/*Includes*/
#include <stdio.h>
/*File includes*/

/*Functions definitions*/
int fibonacci(int);
/*Main*/
int main()
{
    printf("%d",fibonacci(50));
    return 1;
}
/*Functions bodies*/
int fibonacci(int num)
{
    if(num <= 1)
    {
        return num;   
    }
    else
    {
        return (fibonacci(num-1) + fibonacci(num-2));
    }
}