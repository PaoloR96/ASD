#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int test = 0;
    int N = 0, M = 0;
    char Matrice[MAX][MAX];
    Coordinate C[MAX];
    char Parola[MAX];
    printf("SAMPLE INPUT:\n");
    // Leggo il numero di test
    scanf("%d", &test);
    for (int i = 0; i < test; i++){
        // 1. Leggo PRIMA la parola
        scanf("%s", Parola);
        // 2. Leggo POI le dimensioni della matrice
        scanf("%d %d", &N, &M);
        int lenParola = strlen(Parola);
        // 3. Riempio la matrice
        RiempiMatrice(Matrice, N, M);
        // 4. Cerco la parola
        TrovaParola(C, Parola, Matrice, 0, 0, N, M, lenParola, 0);
        // 5. Stampo sempre END alla fine del caso di test, come richiesto
        printf("END\n");
    }
    system("pause");
    return 0;
}