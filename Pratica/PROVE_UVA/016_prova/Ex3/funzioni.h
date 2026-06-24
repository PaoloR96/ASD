#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 1000 //numero massimo di elefanti
typedef struct {
     long W;   //peso elefante
     long S;   //QI elefante
     int id;
}Elefante;
int  InserimentoValori(Elefante Valore[MAX]);
/*Metodi per gestire ordinamento + la logica DP*/
int comparaElefanti(const void *a, const void *b);
void InizializzaDP(int DP[MAX],int Parent[MAX],int dim);
void CalcolaDP(Elefante Valore[MAX],int DP[MAX],int Parent[MAX],int dim);
int TrovaMax(int DP[MAX],int dim);
void StampaPercorsoRicorsivo(Elefante Valore[MAX], int Parent[MAX], int i);



#endif
