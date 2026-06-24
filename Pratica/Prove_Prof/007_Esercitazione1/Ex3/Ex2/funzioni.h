#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
extern int DP[MAX][MAX];
/*Metodi*/
void InitDP(int DP[MAX][MAX],int W[MAX][MAX],int NumColonne,int NumRighe);
void CalcolaDP(int DP[MAX][MAX],int W[MAX][MAX],int numRighe,int numColonne);
int TrovaRiga(int ValoreScelto,int vGiu,int vStessa,int vSu,int rigaSu,int rigaStessa,int rigaGiu,int numRighe);
int TrovaIlMinimo(int DP[MAX][MAX], int colonna, int numRighe);
void ElaboraPercorso(int DP[MAX][MAX],int numRighe,int numColonne);
int min2(int a,int b,int c);
#endif
