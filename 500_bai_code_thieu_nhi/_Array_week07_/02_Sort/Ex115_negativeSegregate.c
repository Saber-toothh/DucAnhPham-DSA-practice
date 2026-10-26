#include <stdio.h>

void swap (int A[], int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
    return;
}

void Segregate (int A[], int n){
    int pivot = 0;
    int i = 0; int j = n-1;
    while (i<= j){
        while (i < n && A[i] < pivot) i++;

        while (j >= 0 && A[j] >= pivot) j--;

        if (i <= j) {
            swap(A, i, j);
            i++;
            j--;
        }
    }
}

int main()
{
    int A[] = {0, -1, 2, -3, 0, -5};
    int n = sizeof(A)/sizeof(A[0]);
 
    Segregate(A, n);
 
    for (int i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }
 
    return 0;
}