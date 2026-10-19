#include <stdio.h>
#define N 13

void swap (int A[], int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
    return;
}

void bubbleSort (int A[], int n){
    for (int i = 0; i<n-1; i++){
        for (int j = n-1; j>i; j--){
            if (A[j] < A[j-1]){
                swap (A, j, j-1);
            }
            else continue;
        }
        for (int k = 0; k<n; k++){
            printf("%-5d", A[k]);
        }
        printf ("\n");
    }
}

int main(){
    int A[N] = {101, 23, 57, 13, 25, 121, 87, 36, 13, 204, 111, 89, 59};
    bubbleSort (A, N);
    return 0;
}