#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h" 

int InserisciSegmento(Segmento S[MAX]) {
    int Ltmp = 0, Rtmp = 0;
    int index = 0;
    while (index < MAX) {
        if (scanf("%d %d", &Ltmp, &Rtmp) != 2) break;
        if (Ltmp == 0 && Rtmp == 0) break;
        
        S[index].L = Ltmp;
        S[index].R = Rtmp;
        index++;
    }
    return index; //restituisco quanti segmenti sono stati effettivamente letto
}

int ComparaValori(void const *a, void const *b) {
    Segmento *s1 = (Segmento*)a;
    Segmento *s2 = (Segmento*)b;
    // Ordino per L crescente
    if (s1->L != s2->L) {
        return s1->L - s2->L;
    }
    // In caso di parità, ordino per R decrescente 
    return s2->R - s1->R;
}

//VAR GLOBALE
Segmento scelti[MAX];
int num_scelti = 0;

void StampaSequenza() {
    printf("%d\n", num_scelti);
    for (int k = 0; k < num_scelti; k++) {
        printf("%d %d\n", scelti[k].L, scelti[k].R);
    }
}

void CalcolaSequenza(Segmento S[MAX], int M, int n) {
    /* Definisco le variabili */
    int corrente_a_destra = 0;
    int i = 0;
    int possibile = 1; // assumiamo sia possibile all'inizio
    
    num_scelti = 0; // RESET: Azzera il contatore globale per il caso di test corrente

    while (corrente_a_destra < M) {
        int migliore_R = corrente_a_destra;
        int indice_migliore = -1;
        
        // Logica Greedy
        while (i < n && S[i].L <= corrente_a_destra) {
            if (S[i].R > migliore_R) {
                migliore_R = S[i].R;
                indice_migliore = i;
            }
            i++;
        }
        
        if (indice_migliore == -1) {
            possibile = 0; // Trovato un buco nella copertura
            break;
        }
        
        // Seleziono il segmento migliore trovato
        scelti[num_scelti++] = S[indice_migliore];
        corrente_a_destra = migliore_R;
    }
    
    // Controllo finale
    if (possibile && corrente_a_destra >= M) {
        StampaSequenza();
    } else {
        printf("0\n");
    }
}