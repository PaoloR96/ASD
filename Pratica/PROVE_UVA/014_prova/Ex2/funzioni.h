#ifndef FUNZIONI_H
#define FUNZIONI_H
#define  MAX 51
#include <string.h>

typedef struct {
    char V[MAX];           // Le lettere disponibili (ordinate)
    int usato[MAX];        // Array di flag (0 o 1) per il backtracking
    char inputOriginale[MAX]; // La stringa da confrontare [cite: 20]
    int dimensione;        // Lunghezza effettiva della stringa [cite: 18]
} Sequenza;

/* Variabili globali*/
extern int trovato;
extern int concluso;
extern char stringaTarget[MAX]; 

void RiempiCasiTest(Sequenza *s, char stringaInput[]);
void TrovaSequenza(char insieme[], char attuale[], int usato[], int pos, int dim);
int compara(const void *a, const void *b);

#endif
