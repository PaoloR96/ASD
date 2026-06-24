#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
/*Metodi*/
void RiempiVettore(int A[MAX],int dim);
int ComparaElementi(const void*a,const void*b);
int RicercaElementi(int A[MAX],int dim,int target);
void TrovaElementiMinori(int A[MAX],int dim);
void StampaRisultati(int Risultato[MAX],int dim);
#endif
