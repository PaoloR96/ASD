#ifndef FUNZIONI_H
#define FUNZIONI_H

#define MAX_N 301      // Per gestire indici da 0 a 300
#define MAX_L 301      // Numero massimo di monete utile per N=300
#define NUMTEST 4

typedef struct {
    int N;
    int L1;
    int L2;
    int quantiNumeri; // Fondamentale per capire quale caso risolvere (1, 2 o 3)
} CasoTest;

//La DP memorizza: DP[numero_monete][somma_raggiunta]
void RiempiCasoTest(CasoTest TestX[MAX_L]);
void ElaboraCasoTest(CasoTest TestX[MAX_L]);
/*metodi per la logica DP*/
void InizializzaDP(long long DP[MAX_L][MAX_N]);
void CalcolaDP(long long DP[MAX_L][MAX_N]);
void CalcolaSequenza1(long long DP[MAX_L][MAX_N],int N);
void CalcolaSequenza2(long long DP[MAX_L][MAX_N],int N,int L1);
void CalcolaSequenza3(long long DP[MAX_L][MAX_N],int N,int L1,int L2);

#endif
