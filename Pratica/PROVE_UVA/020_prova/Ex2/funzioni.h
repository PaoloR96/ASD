#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 10

typedef struct {
    int n; //numero nodi
    int k; //numero archi
    int K[MAX][2]; // ogni arco = coppia (u, v)
}Grafo;

/*Varibili globali*/
extern int Max;             // Massimo numero di nodi neri trovato finora
extern int SoluzioneOttima[MAX];  // Per salvare i nodi neri della migliore configurazione
extern int Colorato[MAX];         // Array dei colori corrente
/*Metodi*/
void InserisciDati(Grafo * G);
int ColoroNero(int nodo_attuale, Grafo *G);
void ColoraGrafo(int nodo_attuale, Grafo *G);


#endif
