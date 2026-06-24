#ifndef FUNZIONI_H
#define FUNZIONI_H

// Prototipi delle funzioni
void GeneraCombinazioni(int S[],int k,int n);

/*S[] → insieme di numeri da cui scegliere

n → dimensione di S

k → dimensione desiderata della combinazione

start → indice da cui iniziare a cercare nuovi elementi (serve per evitare ripetizioni)

comb[] → array temporaneo che contiene la combinazione parziale

pos → posizione corrente in comb[] (quanti numeri sono già stati scelti)*/
void BackTracking(int S[],int n,int k,int start,int comb[],int pos);

void StampaCombinazioni(int S[],int k);


#endif
