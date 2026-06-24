#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int Matrice[MAX][MAX];
    int test;
    int N = 0, M = 0;
    int Ris[MAX];
    char Nomi[MAX][100]; // Vettore di stringhe per memorizzare i nomi delle aree
    printf("SAMPLE INPUT:\n");
    // Leggo il numero di casi di test (prima riga dell'input)
    if (scanf("%d", &test) != 1) return 0;

    for (int i = 0; i < test; i++){
        // 1. Leggo il NOME, le righe (N) e le colonne (M)
        scanf("%s %d %d", Nomi[i], &N, &M);
        
        // 2. Inizializzo e Riempio la matrice
        InizializzaMatrice(Matrice, N, M);
        RiempiMatrice(Matrice, N, M);
        
        // 3. Applico il backtracking
        MaxPercorsoGlobale = 0;
        
        // DEVO provare a far partire lo snowboarder da OGNI singola cella
        for (int r = 0; r < N; r++){
            for (int c = 0; c < M; c++){
                // Passo lunghezza = 1 perché la cella di partenza conta come 1 passo
                TrovaLunghezzaPercorso(Matrice, N, M, r, c, 1);
            }
        }
        
        // Salvo il risultato usando l'indice 'i' del ciclo test
        Ris[i] = MaxPercorsoGlobale;
    }
    
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < test; i++){
        // Stampo esattamente nel formato richiesto: "Nome: Valore"
        printf("%s: %d\n", Nomi[i], Ris[i]);
    }
    
    system("pause");
    return 0;
}
/*
Complessità è O(K^(NM)), dove K=4 rappresenta le quattro direzioni possibili (su, giù, destra e sinistra). 
Il termine N*M deriva dal caso peggiore, in cui il percorso può estendersi fino a coprire l’intera matrice. 
A differenza del problema del labirinto, dove sono noti punto di partenza e arrivo e quindi compare un fattore (N+M), 
in questo caso il percorso può coinvolgere tutte le celle della matrice, portando a un fattore N*M.

*/