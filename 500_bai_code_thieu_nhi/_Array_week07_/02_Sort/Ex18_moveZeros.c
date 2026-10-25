#include <stdio.h>

void swap (int A[], int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
    return;
}

void moveZeros(int A[], int n)
{
    int zeroIndex = 0;
    for (int i = 0; i < n; i++){
        if (A[i] != 0 ){
            swap (A, i, zeroIndex);
            zeroIndex++;
        }
    }
}

int main()
{

    int A[] = {0, 0, 0, 0};
    int n = sizeof(A) / sizeof(A[0]);

    moveZeros(A, n);
 
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}