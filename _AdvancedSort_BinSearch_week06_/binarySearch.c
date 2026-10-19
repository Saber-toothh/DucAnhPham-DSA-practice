#include <stdio.h>
#include "quickSort.c"


int binarySearch (int A[], int n, int x){
    int left = 0; int right = n-1;
    while (left<=right){
        int k = (left+right)/2;
        if(x == A[k]) return k;
        if (x < A[k]) right = k-1;
        else left = k+1;
    }
    return -1;
}

int main()
{
    int A[N] = {101, 23, 57, 13, 25, 121, 87, 36, 13, 204, 111, 89, 59};
    quickSort(A, 0, N-1);

    int finding = binarySearch(A, N, 13);
    printf ("The index of the number you find: %d\n", finding);
    return 0;
}