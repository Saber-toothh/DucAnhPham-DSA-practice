#include <stdio.h>
#define N 13

void swap (int A[], int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
    return;
}

void quickSort (int A[], int first, int last)
{
    if (first >= last) return;
    int pivot = first;
    int i = first+1;
    int j = last;
    while (i <= j){
        while (i <= last && A[i] <= A[pivot]) i++;
        while (j >= first && A[j] > A[pivot]) j--;
        
        if (i < j) {
                swap (A, i, j);
        }
    }
    swap (A, j, pivot);

    quickSort (A, first, j-1);
    quickSort (A, j+1, last);
}
