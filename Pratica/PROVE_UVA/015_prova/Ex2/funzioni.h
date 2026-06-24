#ifndef FUNZIONI_H
#define FUNZIONI_H

extern int conteggio; // Contatore globale per le sequenze hard trovate

void CalcolaSequenza(char SequenzaK[], int index, int L, int n);
int IsHard(char SequenzaK[], int lunghezza);
void  StampaSequenza(char SequenzaK[], int lunghezza);

#endif
