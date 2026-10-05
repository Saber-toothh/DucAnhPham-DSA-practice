#include <stdio.h>
#include <math.h>
#include "stack.c"

int HanoiTower (int n, char start, char destination, char transit){
    if (n<0) { printf("Invalid number of disks\n"); return 0; }

    Stack task;
    initStack(&task);
    Type bigTask = {n ,'A', 'B', 'C'};
    push(&task, bigTask);

    while (!isEmpty(&task)){

        Type currentTask = top(&task);
        pop(&task);

        if(currentTask.n == 1 || currentTask.n < 0) {
            int diskNo = (currentTask.n < 0) ? -currentTask.n : 1;

            
            printf ("Move disk %d from %c to %c\n",
                diskNo, currentTask.start, currentTask.destination);
        }
        else {
            Type step1 = {currentTask.n - 1, currentTask.start, currentTask.transit, currentTask.destination};
            Type step2 = {-currentTask.n, currentTask.start, currentTask.destination, currentTask.transit};
            Type step3 = {currentTask.n - 1, currentTask.transit, currentTask.destination, currentTask.start};
            push(&task, step3);
            push(&task, step2);
            push(&task, step1);
        }

    }
    return pow(2,n) - 1;
}

int main ()
{
    // case n = 3
    printf ("Total: %d moves\n", HanoiTower(3, 'A', 'B','C'));

    // case n<0
    printf ("Total: %d moves\n", HanoiTower(-2, 'A', 'B','C'));
    return 0;
}