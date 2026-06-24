#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    // Precaricamento del set di dati fornito
    SetCentrifuga s = {
        .camere = 5,
        .campioni = 9,
        .masse = {1, 2, 3, 5, 7, 11, 13, 17, 19}
    };

    // Uso della funzione di stampa
    stampaSet(s);
    //1.Ordinamento valori tramite qsort
    qsort(s.masse,s.campioni,sizeof(int),ComparaValori);
    //2. Se il numero di campioni è < 10 MAX CAMPIONI(max 2 * MAX_CAMERE),devo aggiungere 0 fittizio
    int diff=MAX_CAMPIONI-s.campioni;
    if(diff>0)s=RiempiSequenza(s,diff);
    //3.Somma totale dei campioni+mediaa
    int SommaT=SommaCampioni(s);
    double AM = (double)SommaT /s.camere;
    //4.Calcola Seq
    CalcolaSbilanciamento(s,AM);

    system("pause");
    return 0;
}
/*Comp: O(n*logn)*/