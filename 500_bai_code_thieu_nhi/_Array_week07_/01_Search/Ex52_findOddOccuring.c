#include <stdio.h>

int findOddOccurring(int A[], int n) {
    int result = 0;
    
    for (int i = 0; i < n; i++) {
        result ^= A[i]; 
    }
    
    return result;
}

int main() {
    int A[] = {4, 3, 6, 2, 6, 4, 2, 3, 4, 3, 3};
    int n = sizeof(A) / sizeof(A[0]);
    
    int oddElement = findOddOccurring(A, n);
    printf("Phan tu xuat hien voi so lan le: %d\n", oddElement);
    
    return 0;
}