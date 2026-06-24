#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
   

    system("pause");
    return 0;
}

/*

L'algoritmo non è un backtracking puro ma un'esplorazione deterministica di un cammino univoco, 
poiché i vincoli impediscono sovrapposizioni temporali per la stessa estensione , garantendo un unico arco uscente per ogni nodo.
La ricorsione funge da semplice attraversamento lineare, interrotto solo dal rilevamento di cicli 
tramite controllo dello stato (loop detection) che devia la chiamata all'interno 9999.

Complessità: : O(N * M) per ogni chiamata, dove N è il numero massimo di interni (profondità della catena) 
                                                M è il numero di regole da scansionare a ogni passo

*/