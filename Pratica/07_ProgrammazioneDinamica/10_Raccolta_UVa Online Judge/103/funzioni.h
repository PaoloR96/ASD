#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <limits.h>
#include <stdbool.h>

/* definizione costanti */
#define K 30

/* definizione variabili globali */
extern int Ldp[K];
extern int Pdp[K];
/*Definizione Struttura dati Scatola*/
typedef struct {
    int id;
    int dimensioni[10];
} Scatola;
/* metodi */
void OrdinaScatole(Scatola lista[], int k, int n);
int confronta_dimensioni(const void *a, const void *b);
bool IsCompatibile(Scatola A, Scatola B,int n);
void InitDp(int Ldp[K],int Pdp[K],int k);
void CalcolaSequenzaMassima(Scatola lista[], int k, int n);
void StampaPercorso(int indice, Scatola lista[]);
#endif