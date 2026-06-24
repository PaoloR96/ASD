#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 22
#define MAX_N 10001 

typedef struct {
    int capResidua;
    int valori[MAX];
    int contatoreScelti;
} Risultato;

// Matrice di posizione
extern bool preso[MAX][MAX_N];

void InizializzaDP(int DP[MAX_N], int N);
int CalcolaDP(int DP[MAX_N], int Brani[MAX], int numeroBrani, int N);
int max2(int a, int b);
Risultato TrovaElementiInsieme(int Brani[MAX], int capResidua, int numBrani);
void StampaRisultati(Risultato R);

#endif
