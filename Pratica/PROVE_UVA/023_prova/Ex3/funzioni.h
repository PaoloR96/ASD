#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX_N 50
#define MAX_L 1000
/*Struttura dati*/
typedef struct {
        int l; //lunghezza del bastone da tagliare
        int n; //numero di tagli da effettuare
        int punti[MAX_N];//punti in cui devono essere fatti i tagli
}CasoTest;
/*Variabile Globale*/
extern int DP[MAX_N][MAX_N];
/*Metodi*/
void InserisciCasoTest(CasoTest *T, int lTmp);
void InizializzaDP(int DP[MAX_N][MAX_N],int N);
int CalcolaDP(int DP[MAX_N][MAX_N], int P[MAX_N], int N);
int min2(int a, int b);
#endif
