#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c
int contatoreSoluzioni = 1;
int main() {
    //preparo l'input
    int rigaIniziale = 1; 
    int colonnaIniziale = 1;
    int Soluzione[8];
    for(int i = 0; i < 8; i++)Soluzione[i] = 0;
    //BackTrakking
    CalcolaSoluzione(Soluzione, 0, rigaIniziale, colonnaIniziale);
    
    
    system("pause");
    return 0;
}
/*Complessità: O(N!)*/