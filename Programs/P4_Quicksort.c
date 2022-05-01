/* ⓒ Jakub Nowak 
Program to sort array
Arguments: Array to sort
Return: -
*/


/*Includes*/
#include <stdio.h>
/*Functions definitions*/
void printArray(int array[], int size);
void quicksort(int array [], int low, int high);
int rearrange(int array [], int low, int high);
void swap_elements(int* one, int* two);

/*Main*/
int main() {
  int data[] = {10,80,30,90,40,50,70};
  
  int n = sizeof(data) / sizeof(data[0]);
  
  printf("Unsorted Array\n");
  printArray(data, n);

   // Quicksort
  quicksort(data, 0, n - 1);
  
  printf("Sorted array in rising order: \n");
  printArray(data, n);
  
}
/*Functions bodies*/

// Function to print array elements
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

//Function that sort the array
void quicksort(int array[], int low, int high)
{
    if(high > low)
    {
        // Rearange array
        int piv = rearrange(array, low, high);
        //Selected high value is the greatest
        while(piv == -1 && high >0)
        {
            high -=1;
            piv = rearrange(array, low, high);
        }
        //Recursive left part
        quicksort(array, low, piv-1);
        //Recursive right part
        quicksort(array, piv+1, high);
    }
}

// Function to sort and return divde point
int rearrange(int array [], int low, int high)
{
    int pivot = array[high];
    int second_pointer = low -1;

    //Find first element greater or equal to pivot
    for(int i=low;i<high;i++)
    {
        if(array[i] >= pivot)
        {
            second_pointer = i;
            break;
        }
    }
    if(second_pointer == low -1)
    {
        //Pivot is the greatest element
        return -1;
    }
    //Compare pivot with other elements
    for(int i=second_pointer;i<high;i++)
    {
        if(array[i] < pivot)
        {
            swap_elements(&array[i], &array[second_pointer]);
            second_pointer++;
        }
    }
    //Swap pivot and greater element
    swap_elements(&array[second_pointer], &array[high]);
    //Return pivot point
    return second_pointer;
}

//Function to swap elements
void swap_elements(int* one, int* two)
{
    int temp = *one;
    *one = *two;
    *two = temp;
}