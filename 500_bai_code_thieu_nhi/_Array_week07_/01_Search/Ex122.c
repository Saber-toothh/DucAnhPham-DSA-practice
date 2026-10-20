#include <stdio.h>

int binarySearch (int A[], int n, int target){
    int left = 0; int right = n-1;
    while (left<=right){
        int k = (left+right)/2;
        if(target == A[k]) return k;
        if (target < A[k]) right = k-1;
        else left = k+1;
    }
    return -1;
}

int searchFirst (int A[], int n, int target){
    int pivot = binarySearch (A, n, target);
    if(pivot == -1){
        return -1;
    }
    else{
        int first = pivot - 1;
        while (A[first] == A [first -1]) first--;
        return first;
    }
}

int searchLast (int A[], int n, int target){
    int pivot = binarySearch (A, n, target);
    if(pivot == -1){
        return -1;
    }
    else{
        int last = pivot + 1;
        while (A[last] == A [last -1]) last++;
        return last-1;
    }
}

int main () 
{
    int A[6] = {5, 5, 5, 6, 7, 8};
    int target = 5;

    printf ("%d, %d", searchFirst(A, 6, target), searchLast(A, 6, target) );

    return 0;
}

