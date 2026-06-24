#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    int tagli[] = {5, 10, 20, 50, 100, 200}; 
    CasoTest T[MAX];
    int index = 0;
    float target_f;
    printf("SAMPLE INPUT:\n");
    // 1. Fase di input
    while (index < MAX) {
        if (RiempiCasoTest(T[index].monete)) break;
        scanf("%f", &target_f);
        T[index].target = (int)(target_f * 100 + 0.5); // Arrotondamento per 5c
        index++;
    }
     printf("SAMPLE OUTPUT:\n");
    int nCasi = index;
    int DpUtente[DIM_MAX], DpNegoziante[DIM_MAX];

    // 2. Calcolo DP Negoziante una sola volta (monete illimitate) 
    InitDp(DpNegoziante);
    CalcolaDpNegoziante(tagli, DpNegoziante);

    // 3. Elaborazione casi
    index = 0;
    while (index < nCasi) {
        InitDp(DpUtente);
        CalcolaDpUtente(T[index].monete, tagli, DpUtente);
        minTotale(DpNegoziante, DpUtente, T[index].target);
        index++;
    }
    system("pause");

    return 0;
}

