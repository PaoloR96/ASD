#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"  // Include il file header
void RiempiCasoTest(char tabella[MAX][MAX],int N){
    for (int i = 0; i < N; i++){
          scanf("%s", tabella[i]);
    }
}

void ElaboraCasoTest(char tabella[MAX][MAX],int N){
        int visited[MAX][MAX] = {0};
        char parolaTemp[MAX_LUN];
        totaleParole = 0;
        // Avvio ricerca da ogni cella 
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                memset(visited, 0, sizeof(visited));//inizializzo visited a 0
                visited[i][j] = 1;//metto a 1 il punto di partenza
                TrovaSequenza(tabella, visited, i, j, parolaTemp, 0, N);
            }
        }
        // Ordinamento finale
        if (totaleParole > 0) {
            qsort(listaParole, totaleParole, MAX_LUN, comparaParole);
            StampaRisultati();
        }
}











void TrovaSequenza(char tabella[MAX][MAX], int visited[MAX][MAX], int r, int c, char parolaAttuale[], int lun, int N) {
        //1.Aggiungo la parola
        parolaAttuale[lun]=tabella[r][c];
        parolaAttuale[lun+1]='\0';
        
        int nuovaLun=lun+1;
        //2.Controllo della sequenza
        if(nuovaLun>=3)SalvaInLista(parolaAttuale);
        //3.Esplora le direzione adiacenti
        // Vettore delle direzioni: Sopra, Sotto, Sinistra, Destra e le 4 Diagonali
        int dr[] = {-1,  1,  0,  0, -1, -1,  1,  1};
        int dc[] = { 0,  0, -1,  1, -1,  1, -1,  1};
        for (int i = 0; i < 8; i++) {
            int nr = r + dr[i]; // Nuova riga
            int nc = c + dc[i]; // Nuova colonna
            if(nr>=0 && nr<N && nc>=0 && nc<N){//controllo per verificare che non sfori la cella
                if(visited[nr][nc]==0 && tabella[nr][nc]>tabella[r][c]){
                    visited[nr][nc]=1;//setto a 1 la cella
                    TrovaSequenza(tabella,visited,nr,nc,parolaAttuale,nuovaLun,N);//passo al livello successivo a paritre dall'ultima parola trovata
                    visited[nr][nc]=0; //BACKTRAKKING:torno indietro, in questo modo se la ricorsione non ha successo torno indietro e valuto  un nuovo percorso
                }
            }
        }
}


char listaParole[MAX_PAROLE][MAX_LUN];
int totaleParole=0;
void SalvaInLista(char parolaAttuale[]) {
    // 1. Controllo unicità
    for (int i = 0; i < totaleParole; i++) {
        if (strcmp(listaParole[i], parolaAttuale) == 0) {
            return; // Parola già salvata, esci
        }
    }
    // 2. Controllo limite memoria
    if (totaleParole < MAX_PAROLE) {
        // Copia la stringa nella  matrice
        strcpy(listaParole[totaleParole], parolaAttuale);
        totaleParole++; // Incrementa il contatore globale
    }
}

int comparaParole(const void *a, const void *b) {
    // Cast dei puntatori generici a puntatori di array di caratteri
    const char *parola1 = (const char *)a;
    const char *parola2 = (const char *)b;

    int len1 = strlen(parola1);
    int len2 = strlen(parola2);

    // Criterio 1: Le parole più corte vengono prima
    if (len1 != len2) return len1 - len2; 

    // Criterio 2: A parità di lunghezza, ordine lessicografico ASCII
    return strcmp(parola1, parola2);
}


void StampaRisultati() {
    // Se non ci sono parole legali 
    if (totaleParole <= 0) return;
    // Stampo la matrice listaParole 
    for (int i = 0; i < totaleParole; i++) printf("%s\n", listaParole[i]);
}