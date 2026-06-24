#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT: \n");
    CasoTest ct;
    int N=0,index=0;
    int Risultato[100];
    scanf("%d",&N);
    for (int i = 0; i < N; i++){
        //1.Inserisco i dati per l'iesimo caso di test
        // Riempio tutte le classi previste per questo test case 
        scanf("%d %d", &ct.budget, &ct.numeroClassi);
        for (int j = 0; j < ct.numeroClassi; j++) RiempiClasse(&ct, j);
        
        //2.Inizializza DP
        InitDP(DP,ct.numeroClassi,ct.budget);
        //3.Calcola DP
        Risultato[i]=CalcolaDP(DP,ct);
    }
    printf("SAMPLE OUTPUT: \n");
    for (int i = 0; i < N; i++){
        if (Risultato[i] != -1) {
            printf("%d\n", Risultato[i]);
        } else {
            printf("denaro insufficiente\n");
        }
        
    }
    system("pause");
    return 0;
}
/*
Complessità: O(numeroClassi*Budget*NumeroProdottiPerClasse)

Questo problema rappresenta una variante del problema dello zaino con più oggetti (multi-choice knapsack problem).

Complessità:
Per ogni budget b e per ogni possibile prezzoX, si esegue il seguente controllo:

Se b >= prezzoX e DP[i-1][b-prezzoX] è valido (diverso da -1), allora:

DP[i][b] = max(DP[i][b], DP[i-1][b-prezzoX] + prezzoX)

Significato:
Si prende il massimo tra due alternative:
- non selezionare l'oggetto corrente, mantenendo il valore già presente in DP[i][b];
- selezionare l'oggetto della classe i con prezzo prezzoX, aggiungendo il suo valore al miglior risultato ottenuto con il budget rimanente.


*/