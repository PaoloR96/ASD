#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    Solve(1,1);


    system("pause");
    return 0;
}

/*
Complessità:O(N!)


Brute force senza controlli: O(N^N), perché ogni colonna ha sempre N scelte indipendenti.

Approccio con permutazioni:

1. Riduzione delle scelte
Ogni regina elimina una riga:
Col1: N, Col2: N-1, Col3: N-2, ...→ O(N!)

2. Pruning delle diagonali
O(N!) è un limite superiore:
- si eliminano anche le diagonali
- il backtracking interrompe subito i rami invalidi
→ molte configurazioni non vengono esplorate



*/