#ifndef FUNZIONI_H
#define FUNZIONI_H
#include<stdbool.h>
#define MAX 200                 // massimo numero di righe o colonne
#define MAX_CELLE (MAX * MAX)  // massimo numero totale di elementi della bitmap
typedef struct {
    char formato;
    int righe;
    int colonne;
    char caratteri[MAX_CELLE + 1];
} Mappa;

/*Metodi*/
void RiempiMappa(Mappa *M);
void ConvertiB_to_D(char Stringa[], int Matrice[MAX][MAX], int righe, int colonne);
void CalcolaSequenza(int Matrice[MAX][MAX],int rInizio, int rFine, int cInizio, int cFine);
int ControllaRegione(int Matrice[MAX][MAX],int rInizio,int rFine,int cInizio,int cFine);

#endif

