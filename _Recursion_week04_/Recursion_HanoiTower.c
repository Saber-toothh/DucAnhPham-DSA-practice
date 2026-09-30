#include <stdio.h>
#include <math.h>

int HanoiTower (int n, char start, char destination, char transit){
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", start, destination);
        return 1;
    }
    HanoiTower (n-1, start, transit, destination);
    printf ("Move disk %d from %c to %c\n", n, start, destination);
    HanoiTower (n-1, transit, destination, start);
    return pow(2,n) - 1;
}

int main ()
{
    printf ("Total: %d moves\n", HanoiTower(3, 'A', 'B','C'));
    return 0;
}


