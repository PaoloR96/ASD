#ifndef FUNZIONI_H
#define FUNZIONI_H
#include <string.h>
#include <stdbool.h>
#define MAX_VISITATI 100
typedef struct {
    char lista[MAX_VISITATI][5];
    int contatore;
} Percorso;

typedef struct {
    char sorgente[5];
    int inizio;
    int durata;
    char destinazione[5];
} Regola;

extern Regola archivio[100]; 
extern int num_regole;
/*Metodi*/
void trova_destinazione(char attuale[], int ora, Percorso *p, char risultato[]);
bool gia_visitato(char estensione[], Percorso *p);
#endif
