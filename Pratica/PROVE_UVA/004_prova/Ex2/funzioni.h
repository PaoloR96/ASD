#ifndef FUNZIONI_H
#define FUNZIONI_H

/* dichiarazione costanti */
#define N 100     // numero massimo parole
#define W 256     // lunghezza massima parola 
#define R 1000    // numero massimo regole
#define RL 256    // lunghezza massima regola 

typedef struct {
    char parola[N][W];   // dizionario
    char regole[R][RL];  // regole
    int n;               // numero parole
    int m;               // numero regole
} Dizionario;

/* Metodi */
void stampaDizionario(Dizionario d);
// La funzione ora riceve la password che sta costruendo "passo dopo passo"
void ElaboraPassword(Dizionario d, int indexRegola, char regola_corrente[], char password_accumulata[]);

#endif