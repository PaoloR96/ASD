#ifndef FUNZIONI_H
#define FUNZIONI_H

#define MAX_H 30   // Altezza massima della matrice
#define MAX_D 100  // Larghezza massima della matrice

// Inserisce gli elementi in una riga
void InserisciElementi(int A[], int size);

// Stampa l'intera matrice delle pile
void StampaPila(int A[][MAX_D], int h, int d);

// Trova la posizione del massimo nella sotto-pila A[0 ... d-1]
int TrovaPosMAX(int A[], int d);

// Esegue un flip dei primi 'pos' elementi e stampa la posizione
void Flip(int A[], int pos, int n);

// Ordina una riga della pila ricorsivamente (pancake sort)
void OrdinaPila(int A[], int total_size, int current_size);

// Ordina tutte le pile della matrice e stampa i flip
void OrdinaElementi(int A[][MAX_D], int h, int d);

#endif

