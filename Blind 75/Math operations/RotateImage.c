/*
    Explaination:
    Swaping is done by layers starting from outside. Each side takes n-1 transitions. Where n is the size of matrix.
    01 02 03 04
    05 06 07 08
    09 10 11 12
    13 14 15 16
    First swap corners  01 -> 04 -> 16 -> 13 -> 01
    Then move to another one 02 -> 08 -> 15 -> 09 -> 02
    Each swap is a rectange just tilted.
    After completing each layer program moves inside to another subproblem.
    If left and right pointers meet it is the end  

*/
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    unsigned int L = 0;
    unsigned int P = matrixSize-1;
    int temp1 = 0;
    int temp2 = 0;
    while(L<P)
    {
        for(int i=0;i<(P-L);i++)
        {
            temp1 = matrix[L+i][P];
            matrix[L+i][P] = matrix[L][L+i];
            temp2 = matrix[P][P-i];
            matrix[P][P-i] = temp1;
            temp1 = matrix[P-i][L];
            matrix[P-i][L] = temp2;
            matrix[L][L+i] = temp1;
        }
        L+=1;
        P-=1;
    }
}