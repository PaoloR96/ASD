#ifndef FUNZIONI_H
#define FUNZIONI_H

#define MAX 25             // Dimensione massima N
#define MAX_PAROLE 50000   // Numero massimo di parole uniche
#define MAX_LUN 405        // N*N + 1
/*Variabili globali*/
extern char listaParole[MAX_PAROLE][MAX_LUN];
extern int totaleParole;
typedef struct{
    /* data */
    int dimensione;
    char Matrice[MAX][MAX];
}CasoTest;


void RiempiCasoTest(char tabella[MAX][MAX],int N);
void ElaboraCasoTest(char tabella[MAX][MAX],int N);
void TrovaSequenza(char tabella[MAX][MAX], int visited[MAX][MAX], int r, int c, char parolaAttuale[], int lun, int N);
void SalvaInLista(char parolaAttuale[]);
int comparaParole(const void *a, const void *b);
void StampaRisultati();

#endif
