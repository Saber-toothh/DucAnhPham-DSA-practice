#include <stdio.h>
#define N 12

void swap (int A[], int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
    return;
}

void DutchFlag (int A[], int last) {
    int mid = 1;
    int first = 0;
    int current = 0;

    while (current <= last){
        if (A[current] > mid)
        {
            swap (A, current, last);
            last--;
        }
        else if (A[current] < mid){
            swap (A, current, first);
            first++; current++;
        }
        else {
            current++;
        }

    }
}

int main()
{
    int A[] = { 0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0 };
    DutchFlag (A, N-1);

    for (int i = 0; i<N; i++){
        printf("%d\t", A[i]);
    }
    return 0;
}