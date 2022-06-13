/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    (*returnSize) = matrixSize*(*matrixColSize);
    int* arr = malloc((*returnSize) * sizeof(int));
    int L, T = 0;
    int D = matrixSize;
    int P = (*matrixColSize);
    int i,j,q = 0;
    while(L<P && T<D)
    {
        for(i = L, j = T; i<P;i++,q++)
            arr[q]=matrix[j][i];
        for(i = P-1, j = T+1; j<D;j++,q++)
            arr[q]=matrix[j][i];
        if (j == T+1 || (P-L)==1)
                break;
        for(i = P-2, j = D-1; i>=L;i--,q++)
            arr[q]=matrix[j][i];
        for(i = L, j = D-2; j>T;j--,q++)
            arr[q]=matrix[j][i];
        L++;
        P--;
        T++;
        D--;
    }
    return arr;
}