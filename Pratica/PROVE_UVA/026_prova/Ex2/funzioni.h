#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 21
extern int InsiemeAtt[MAX];
extern int numeroTotPercosi;
/*Metodi*/
void CalcolaSequenza(int valoreAtt, int target, int ListaAdiacenza[MAX][MAX], int visitato[MAX], int pos);
void StampaSequenza(int InsiemeAtt[MAX],int dim);
#endif
