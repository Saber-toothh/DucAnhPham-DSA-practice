#include <stdio.h>

int binarySearch (int A[],int left, int right, int target){

    while (left<=right){
        int k = (left+right)/2;
        if(target == A[k]) return k;
        if (target < A[k]) right = k-1;
        else left = k+1;
    }
    return -1;
}

int searchFirst (int A[], int n, int target){
    int k = binarySearch (A, 0, n-1, target);
    int first;
    if (k == -1){
        return -1;
    }
    else {
        while ( k != -1){
            first = k;
            k = binarySearch (A, 0, k-1, target);
        }
        return first;
    }
}

int searchLast (int A[], int n, int target){
    int k = binarySearch (A, 0, n-1, target);
    int last;
    if (k == -1){
        return -1;
    }
    else {
        while ( k != -1){
            last = k;
            k = binarySearch (A, k+1, n-1, target);
        }
        return last;
    }
}

int main () 
{
    int A[6] = {5, 5, 5, 6, 7, 8};
    int target = 5;

    printf ("%d, %d", searchFirst(A, 6, target), searchLast(A, 6, target) );

    return 0;
}

