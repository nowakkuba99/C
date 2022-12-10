/* Program displaying useage of references in c++ */
/*
    Reference create an alias for a variable.
*/

/* Includes */
#include <iostream>

/* Defines */
#define PRINT(x) std::cout<<x<<"\n";


void someFun(int* var)
{
    (*var)++;
}

void someFun2(int& varRef)
{
    varRef++;
}

/* Main */
int main()
{
    // Variables
    int someVar = 10;
    PRINT(someVar);
    // Classic pointer
    int* ptr = &someVar;

    // Reference
    int& ref = someVar;

    // Edit someVar with pointer
    *ptr = 5;
    PRINT(someVar);
    // Edit someVar with referene
    ref = 8;
    PRINT(someVar);

    // Reset value
    someVar = 0;
    // Increment through pointer function
    someFun(&someVar);
    PRINT(someVar);
    // Increment through reference
    someFun2(someVar);
    PRINT(someVar);

    return 0;
}