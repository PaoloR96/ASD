#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    Stack s;
    int value=0;
    //inizializzazione Stack
    initStack(&s);
    printf("Stampa Stack:");
    StampaStack(&s);
    push(&s,5);
    push(&s,10);
    push(&s,15);
    printf("Stampa Stack:");
    StampaStack(&s);
    value=pop(&s);
    printf("Valore rimosso:%d",value);
    printf("\n");
    printf("Stampa Stack:");
    StampaStack(&s);
  

  

    system("pause");
    return 0;
}
