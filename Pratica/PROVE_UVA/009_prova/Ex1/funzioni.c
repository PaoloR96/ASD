#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
void stampaAlbero(Nodo array[], int count) {  
    for (int i = 0; i < count; i++) {
        if (array[i].n == 0 && strlen(array[i].s) == 0) {
            // Nodo speciale che rappresenta ()
            printf("() ");
        } else {
            printf("(%d,%s) ", array[i].n, array[i].s);
        }
    }
    printf("\n---\n");
}
//Salvo la lunghezza di ogni nodo in questo vettore
void DefinisciLunghezzaNodi(Nodo N[],int dim){
    for (int i = 0; i < dim; i++)
        N[i].lunghezza = strlen(N[i].s);;// salvo la lunghezza della stringa del nodo
}

int compareLivello(const void* a, const void* b) {
    const Nodo* nodoA = (const Nodo*)a;
    const Nodo* nodoB = (const Nodo*)b;

    // 1. Priorità alla lunghezza (Livello)
    if (nodoA->lunghezza != nodoB->lunghezza) {
        return nodoA->lunghezza - nodoB->lunghezza;
    }

    // 2. A parità di lunghezza, ordine alfabetico (L prima di R)
    return strcmp(nodoA->s, nodoB->s);
}

/*


Una volta che i nodi sono in ordine, il "padre" di un nodo si trova sempre in una posizione precedente nel vettore. 
Usando un puntatore che scorre in avanti senza mai tornare indietro, 
trasformi una ricerca potenzialmente lenta in una scansione lineare O(N)


*/
int IsCompleto(Nodo N[], int dim) {
    if (dim == 0) return 0;
    // 1. La radice DEVE essere il primo elemento (lunghezza 0)
    if (N[0].lunghezza != 0) return 0;
    int p = 0; // Puntatore al potenziale genitore
    
    for (int i = 1; i < dim; i++) {
        // 2. Controllo duplicati: due nodi non possono avere lo stesso percorso 
        if (strcmp(N[i].s, N[i-1].s) == 0) return 0;

        // 3. Ricerca del genitore in O(n)
        char pathPadre[MAX_STR];
        strcpy(pathPadre, N[i].s);
        pathPadre[N[i].lunghezza - 1] = '\0'; // Rimuove l'ultima direzione (L o R)

        // Spostiamo 'p' in avanti solo se necessario. 
        // Poiché N è ordinato, il genitore di N[i] non può essere prima di N[p].
        while (p < i && (N[p].lunghezza < (N[i].lunghezza - 1) || 
               (N[p].lunghezza == (N[i].lunghezza - 1) && strcmp(N[p].s, pathPadre) < 0))) {
            p++;
        }

        // Se p non punta al padre corretto, il percorso è interrotto 
        if (p >= i || strcmp(N[p].s, pathPadre) != 0) return 0;
    }
    return 1;
}