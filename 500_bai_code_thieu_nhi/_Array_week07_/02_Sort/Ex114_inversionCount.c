#include <stdio.h>

int MergeArrays (int A[], int aux[], int left, int mid, int right){
    int inversionCount = 0;
    int i = left; int j = mid +1;
    int k = left;
    while (i<=mid && j <= right){
        if (A[i] > A[j]){
            aux[k] = A[j];
            inversionCount += (mid-i+1);
            k++; j++;
        }
        else {
            aux[k] = A[i];
            k++; i++;
        }
    }
    // copy các phần tử lẻ ra
    while (i<=mid){
        aux[k] = A[i];
        k++; i++;
    }
    while (j <= right){
        aux[k] = A[j];
        k++; j++;
    }

    for (int l=left; l<=right; l++){
        A[l] = aux[l];
    }
    return inversionCount;
}

int Split_Merge (int A[], int aux[], int left, int right){
    if(left >= right) return 0;
    int inversionCount = 0;
    int mid = (left+right)/2;
    inversionCount += Split_Merge (A, aux, left, mid); // de quy voi nua trai
    inversionCount += Split_Merge (A, aux, mid+1, right); // de quy voi nua phai
    inversionCount += MergeArrays (A, aux, left, mid, right);

    return inversionCount;
}

int inversionCount(int A[], int n){
    if (n<2) return 0;
    int aux[n];
    return Split_Merge(A, aux, 0, n-1);
}

int main()
{
    int A[] = { 1, 9, 6, 4, 5 };
 
    int n = sizeof(A)/sizeof(A[0]);
 
    printf("%d", inversionCount(A, n) );
 
    return 0;
}
