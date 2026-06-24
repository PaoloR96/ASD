#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX_N 12
#define MAX_TEST 10
// struttura che rappresenta un singolo caso di test
typedef struct {
    int t;              // valore target (numero totale da ottenere o condizione del problema)
    int n;              // numero di elementi nella lista (1 ≤ n ≤ 12)
    int x[MAX_N];       // array dei valori (ordinati in modo non crescente)
} TestCase;
/*Metodi*/
void stampaTestCase(TestCase t);
void trovaSomme(int A[], int n, int target, int index, int attuale[], int size, int sommaCorrente, int *trovato);
void StampaArray(int A[], int size);
#endif
