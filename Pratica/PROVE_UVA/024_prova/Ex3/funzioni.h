#ifndef FUNZIONI_H
#define FUNZIONI_H

#define N_MAX 8
#define MAX_STATI (1 << (2 * N_MAX)) // 2^16 = 65536 combinazioni possibili

typedef struct {
    int x1; // Coordinata X
    int x2; // Coordinata Y
} Coordinata;
/*Variabile globale*/
extern double DP[MAX_STATI];
/* Prototipi dei metodi */
double CalcolaDistanzaEuclidea(int x1, int y1, int x2, int y2);
int TrovaStudenteLibero(int mask, int n_totale);
void InzitDP(double DP[MAX_STATI]);
double CalcolaDP(double DP[MAX_STATI], Coordinata Studenti[2 * N_MAX], int n_totale);
double min2(double a,double b);

#endif
