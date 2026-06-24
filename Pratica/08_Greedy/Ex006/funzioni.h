#ifndef FUNZIONI_H
#define FUNZIONI_H

#define MAXG 10005
typedef struct {
    int left; // Posizione della stazione
    int right; // Raggio di copertura
} Station;

/*Metodi*/
int ComparaValori(const void *a,const void *b);
 int OttieniRisultatoCopertura(Station stations[MAXG],int G,int L);
void CalcolaIntervalli(Station stations[], int g, Station sequenza[],int L);
#endif
