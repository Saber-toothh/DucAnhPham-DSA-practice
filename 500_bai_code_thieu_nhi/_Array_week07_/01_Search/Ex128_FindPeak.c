#include <stdio.h>

int peakIndex (int A[], int left, int right, int n){
    int mid = (left+right)/2;

    if ((mid == 0 || A[mid] >= A[mid-1]) &&
            (mid == n - 1 || A[mid] >= A[mid+1])) {
        return mid;
    }

    if (mid - 1 >= 0 && A[mid] < A[mid-1]) {
        return peakIndex(A, left, mid-1, n);
    }
    else{
    return peakIndex(A, mid+1, right, n);
    }
}


int findPeak(int A[], int n)
{
    int peak = peakIndex(A, 0, n-1, n);
    return A[peak];
}

int main()
{
    int A[] = { 8, 9, 10, 2, 5, 6 };
    int n = sizeof(A) / sizeof(A[0]);
 
    printf("%d\n", findPeak(A, n));
 
    return 0;
}
 