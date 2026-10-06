#include <stdio.h>
#include <math.h>
#define N 13

int main(){
    int array[N] = {101, 23, 57, 13, 25, 121, 87, 36, 13, 204, 111, 89, 59};

    for (int i =0; i < N-1 ; i++){
        int min = array[i];
        int index = i;
        for (int j = i+1; j<N; j++){
            if (min > array[j]){
                min = array[j];
                index = j;
            }
        }
        int temp = array[i];
        array[i] = array[index];
        array[index] = temp;
        
        for (int k = 0; k<N; k++){
            printf("%-5d", array[k]);
        }
        printf("\n");
    }
    return 0;
}
