/* Program displaying useage of pointers in c++ */
/*
    Pointer is not realy related to type of variable.
    It holds the memory address. The type of pointer holds extra information related to
    data size.
*/

/* Includes */
#include <iostream>

/* Defines */
#define PRINT(x) std::cout<<x<<"\n";

/* Main */
int main()
{
    /* Variables to use later */
    int someVariable = 10;

    /* VOID pointer - holds meomory addres of sth */
    void* ptrVoid = nullptr;    // Create void pointer
    ptrVoid = &someVariable;    // Set ptrVoid to memory address of someVariable
    PRINT(ptrVoid);             // Displays the memory address of someVariable
    
    /* INT pointer - enables to dereference and write to pointer */
    int* ptrInt = nullptr;
    ptrInt = &someVariable;
    PRINT(*ptrInt);             // Dereferenace my using *ptr
    *ptrInt = 70;               // Reassing value to memory addres that ptrInt is pointing to
    PRINT(someVariable);        // Prints 70

    /* Pointers to arrays */
    char* ptrChar = nullptr;    // Creates a pointer of size 1 byte (char)
    ptrChar = new char[8];      // Allocate memory of size 8 bytes and point to the begining
    memset(ptrChar,0,8);        // Set all 8 bytes to value 0

    *ptrChar = 8;               // Set first value to be equal to 8
    *(ptrChar + 2) = 8;         // Set third valur to be equal to 8

    for(int i =0;i<8;i++)
        std::cout<<(int)*(ptrChar+i)<<" ";  // Cast each to int and display
    std::cout<<"\n";

    /* Double pointers */
    char** ptrChar2 = &ptrChar;     // Create pointer that points to char pointer

    **ptrChar2 = 0;                 // Double dereference

    PRINT((int)*ptrChar);

    /* Delete allocated buffer */
    delete[] ptrChar;

    return 0;
}