#include <stdio.h>
#include <math.h>
#define N 13

int main(){
    int array[N] = {101, 23, 57, 13, 25, 121, 87, 36, 13, 204, 111, 89, 59};

    for (int i =0; i < N ; i++){

        for (int j = i; j>0; j--){
            if (array[j] < array[j-1]){
                int temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;
            } else break;
        }
        
        for (int k = 0; k<N; k++){
            printf("%-5d", array[k]);
        }
        printf("\n");
    }
    return 0;
}
