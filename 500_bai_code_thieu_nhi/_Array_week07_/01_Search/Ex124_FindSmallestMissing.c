#include <stdio.h>

int findSmallestMissing (int A[], int n)
{
    int left = 0; int right = n-1;

    while (left <= right){
        int k = (left+right)/2;
        if (A[k] == k){
            left = k+1;
        }
        else right = k-1;
    }
    return left;
}
int main()
{
    int A[] = {2};
    int n = sizeof(A) / sizeof(A[0]);
 
    printf("%d ", findSmallestMissing(A, n));
 
    return 0;
}