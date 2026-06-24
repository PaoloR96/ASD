#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "funzioni.h"  // Include il file header
void RiempiMappa(Mappa *M) {
    char TmpVal;
    scanf(" %c", &TmpVal);
    if (TmpVal == '&')return;
    M->formato = TmpVal;
    scanf("%d %d", &M->righe, &M->colonne);
    int dim = M->righe * M->colonne;
    for (int i = 0; i < dim; i++)scanf(" %c", &M->caratteri[i]);
    M->caratteri[dim] = '\0';
}
void ConvertiB_to_D(char Stringa[], int Matrice[MAX][MAX], int righe, int colonne) {
    int k = 0;

    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            Matrice[i][j] = Stringa[k] - '0'; // da char a int
            k++;
        }
    }
}
void CalcolaSequenza(int Matrice[MAX][MAX],int rInizio, int rFine, int cInizio, int cFine){
        //Condizione Uscita0:
        if (rInizio > rFine || cInizio > cFine) return;
    
        //Passo1:Controlla tutti i bit della matrice
        int Stato=ControllaRegione(Matrice,rInizio,rFine,cInizio,cFine);
        if(Stato!=-1){
            printf("%d", Stato); // È tutto 0 o tutto 1
        }else{
            printf("D"); // La regione è mista
            //Passo 2:Esplorazione dei Quadranti
            int rMezzo=(rInizio+rFine)/2;
            int cMezzo=(cInizio+cFine)/2;
            // Segui l'ordine preciso: Top-Left, Top-Right, Bottom-Left, Bottom-Right
            CalcolaSequenza(Matrice, rInizio, rMezzo, cInizio, cMezzo); // In alto a sinistra
            CalcolaSequenza(Matrice, rInizio, rMezzo, cMezzo + 1, cFine);// In alto a destra
            CalcolaSequenza(Matrice, rMezzo + 1, rFine, cInizio, cMezzo);// In basso a sinistra
            CalcolaSequenza(Matrice, rMezzo + 1, rFine, cMezzo + 1, cFine);// In basso a destra
        }
}
int  ControllaRegione(int Matrice[MAX][MAX],int rInizio,int rFine,int cInizio,int cFine){
    int valore = Matrice[rInizio][cInizio];
    for (int i = rInizio; i <= rFine; i++) {
        for (int j = cInizio; j <= cFine; j++) {
            if (Matrice[i][j] != valore) return -1; // -1 significa "misto" (scrivi 'D')
        }
    }
    return valore; // Ritorna 0 o 1
}
