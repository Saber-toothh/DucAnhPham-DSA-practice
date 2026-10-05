#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef struct {
    int n;          
    char start;   
    char destination;      
    char transit;    
} Type;

typedef struct 
{
    Type info[MAX];
    unsigned int size; //number of current elements
} Stack;

bool isEmpty (Stack* A){
    if (A->size == 0) return true;
    else return false;
}
bool isFull (Stack* A){
    if (A->size == MAX) return true;
    else return false;
}

void initStack (Stack* A) {
    A->size = 0;
}
void push (Stack* A, Type value){
    if (isFull(A)) return;
    A->info[A->size] = value;
    A->size++;
}
void pop (Stack* A) {
    if (isEmpty(A)) return;
    A->size--;
}
Type top (Stack* A){
    if (isEmpty(A)){
        Type nothing = {0, ' ', ' ', ' '};
        return nothing;
    }
    return A->info[A->size-1];
}
