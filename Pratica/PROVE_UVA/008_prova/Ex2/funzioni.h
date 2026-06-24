#ifndef FUNZIONI_H
#define FUNZIONI_H
#define G_MAX 10 //numero tentativi
#define DIM 4 //numero tentativi
typedef struct {
    int Segreto[DIM];//sequenza di numeri
    int x;//Cifre uguali nella stessa posizione.
    int y;//Cifre giuste ma in una posizione sbagliata
}CasoTest;
// extern dice che la definizione reale è in un altro file
extern int soluzioniTrovate;
extern int codiceVincente[DIM];
///////////////////////////////
/*Prototipi delle funzioni*/
void  CalcolaSequenza(CasoTest S[], int G, int guess[DIM], int pos);
int confrontoX(int segreto[DIM], int guess[DIM]);
int confrontoY(int segreto[DIM], int guess[DIM]);



#endif
