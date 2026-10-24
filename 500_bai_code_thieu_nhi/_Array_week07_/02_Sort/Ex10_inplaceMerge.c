#include <stdio.h>

void swap (int A[], int i, int B[], int j) {
    int temp = A[i];
    A[i] = B[j];
    B[j] = temp;
}

int inplaceMerge (int X[], int Y[], int m, int n){
    
    for (int i = 0; i<m; i++){
        if (X[i] > Y[0]){
            swap (X, i, Y, 0);
            int j = 1;
            int pivot = Y[0];
            while (j<n && Y[j] < pivot){
                Y[j-1] = Y[j];
                j++;
            }
            Y[j-1] = pivot;
        }
    }
}

int main()
{
    int X[] = {-5, -1, 4, 7 };
    int Y[] = { -3, 2, 6 };
 
    int m = sizeof(X) / sizeof(X[0]);
    int n = sizeof(Y) / sizeof(Y[0]);

    inplaceMerge(X, Y, m, n);

    for (int i = 0; i<m; i++){
        printf("%d\t", X[i]);
    }
    printf("\n");
    for (int i = 0; i<n; i++){
        printf("%d\t", Y[i]);
    }
    return 0;
}