#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    
    Elefante Elefanti[MAX];
    printf("SAMPLE INPUT:\n");
    int n=InserimentoValori(Elefanti);
    //1.Ordinamento W pesi in senso decrescente ed S QI in senso crescente
    qsort(Elefanti, n, sizeof(Elefante), comparaElefanti);
    printf("SAMPLE OUTPUT:\n");
    int DP[MAX],Parent[MAX];
    //2.Inizializzo la Dp e Parent
    InizializzaDP(DP,Parent,n);
    //3.Calcolo la Dp e aggiorno parent
    CalcolaDP(Elefanti,DP,Parent,n);
    //4.Trovo l'indice Max
    int max_idx=TrovaMax(DP,n);
    printf("%d\n", DP[max_idx]);
    StampaPercorsoRicorsivo(Elefanti,Parent, max_idx);

    

    system("pause");
    return 0;
}

/*Complessità:O(n^2+nlogn)*/
/*Ricorrenza: DP[i] = 1 + max({DP[j]} se:
                        j < i: L'elefante j viene prima di i nella lista già ordinata.
                        W[j] < W[i]: Il peso dell'elefante j è strettamente minore di i.
                        S[j] > S[i]: L'IQ dell'elefante j è strettamente maggiore di i.

*/