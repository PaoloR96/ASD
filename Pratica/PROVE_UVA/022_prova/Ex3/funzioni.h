#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX_S 300
#define MAX_T 100
#include<stdbool.h>

typedef struct {
    int e1; //valore convenzionale
    int e2; //valore InfoTecnologico
}e_coin;



typedef struct {
    int m; //numero di diversi tipi di e-coin esistenti nel problema
    int S; //valore dell'e-modulus da raggiungere
    e_coin E[MAX_S];

}CasoTest;




typedef struct {
    int valore;
    bool stato;
}Risultato;

extern int DP[MAX_S][MAX_S];
/*Metodi*/
void InizializzaDP(int DP[MAX_S][MAX_S],int s);
void RiempiCasoTest(CasoTest *T);
int min2(int a ,int b);
void CalcolaDP(int DP[MAX_S][MAX_S],CasoTest T);
Risultato TrovaSoluzioneOttima(int DP[MAX_S][MAX_S],CasoTest T);


#endif
