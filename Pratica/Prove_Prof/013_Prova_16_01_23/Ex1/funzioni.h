#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 50
#define MAX_DP 25005
typedef struct {
    /* data */
    int M; //numero monete
    int ValoreMoneta[MAX];
}CasoTest;
/*VAR GLOBALE*/
extern int DP[MAX_DP];
/*Metodi*/
void RiempiVettore(CasoTest * ct);
void InitDP(int DP[MAX_DP]);
int CalcolaDP(int DP[MAX_DP],CasoTest ct,int target);
int max2(int a,int b);
int SommaMonete(CasoTest ct);
#endif
