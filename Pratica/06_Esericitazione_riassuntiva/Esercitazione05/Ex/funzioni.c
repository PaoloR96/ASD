#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int RiempiSequenza(char A[], int size) {
    char c;
    for (int i = 0; i < size; i++) {
        scanf(" %c", &c);  
        if(c == '$') return 0; 
        A[i] = c;
    }
    return 1;
}


void StampaSequenza(char A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%c", A[i]);
    }
    printf("\n");
}
/*
i=indice A
j=indice B

*/
int massimoGlobale = 0;  // massimo globale

void TrovaSequenza(char A[], char B[], int d, int i, int j, int massimoLocale) {
    // condizione base: se finiamo una sequenza
    if(i == d || j == d){
        if(massimoLocale > massimoGlobale)
            massimoGlobale = massimoLocale;
        return;
    }

    // se i caratteri coincidono, li prendiamo
    if(A[i] == B[j])
        TrovaSequenza(A, B, d, i+1, j+1, massimoLocale+1);

    // esploriamo sempre i rami "salta A[i]" e "salta B[j]"
    TrovaSequenza(A, B, d, i+1, j, massimoLocale);
    TrovaSequenza(A, B, d, i, j+1, massimoLocale);
}


void TrovaMassimo(char A[], char B[], int d){
    TrovaSequenza(A,B,d,0,0,0);
    printf("Massimo:%d\n",massimoGlobale);
    massimoGlobale=0;
}