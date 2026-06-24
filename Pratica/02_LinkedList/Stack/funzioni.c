#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void initStack(Stack* s) {
    s->count = 0;
    s->capacity = 10;
    for(int i=0;i<s->capacity;i++)s->value[i]=0;
}
void StampaStack(Stack* s) {
    for(int i=0;i<s->capacity;i++)printf("%d ", s->value[i]);
    printf("\n");
}
void push(Stack* s, int val){
    s->value[s->count++]=val;
}
int pop(Stack* s) {
    if (s->count == 0) {
        printf("Stack vuoto!\n");
        return 0;
    } else {
        s->count--;                     
        int val= s->value[s->count];
        s->value[s->count] = 0;
        return val; 
    }
}