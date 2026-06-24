#ifndef FUNZIONI_H
#define FUNZIONI_H

#define MAX_C  10
#define MAX_A  200
#define MAX_L  10001 // 100 metri * 100 + 1

typedef struct {
    int lunTraghetto;
    int Auto[MAX_A];
    int numeroAuto;
} CasoTest;


extern int DP[MAX_A][MAX_L];

/*metodi*/
int InserisciDati(int V[MAX_A]);
void InitDP(int DP[MAX_A][MAX_L], int numeroAuto, int lunTraghetto);
void CalcolaDP(int DP[MAX_A][MAX_L], int Auto[MAX_A], int n_auto, int limite_cm);

#endif