#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funzioni.h"  // Include il file header

void InserimentoDati(char ListaParole[][LEN], int dim){
    for (int i = 0; i < dim; i++){
        scanf("%s", ListaParole[i]);
    }
}

int ComparaLettere(const void* a, const void* b) {
    char ca = *(char*)a;
    char cb = *(char*)b;
    char la = tolower(ca);
    char lb = tolower(cb);

    if (la == lb) {
        // Se le lettere sono uguali (es. 'a' e 'A'), la maiuscola vince 
        return ca - cb; 
    }
    // Altrimenti vince l'ordine alfabetico ignorando il case
    return la - lb;
}

void OrdinaParole(char ListaParole[][LEN], int dim) {
    for (int i = 0; i < dim; i++) {
        qsort(ListaParole[i], strlen(ListaParole[i]), sizeof(char), ComparaLettere);
    }
}

void CreaSequenza(char Input[LEN],char NuovaParola[LEN], int visited[LEN],int index,int dim){
    //1.Condizione di uscita:parola completa
    if (index==dim){
        //Stampo la parola creata
        NuovaParola[index] = '\0'; // Chiudi la stringa("sempre")
        printf("%s\n", NuovaParola);
        return;
    }
    //2.Ricorsione:valuto ogni lettera del mio input per creare la nuova parola
    for (int i = 0; i < dim; i++){
        if (visited[i]) continue; // Salto se la lettera in questa posizione è già usata
        
        char letteraX=Input[i]; //letteraX
        char letteraX_1=Input[i-1];//letteraX+1
        
        //Applico i controlli necessari
            // Salto per evitare duplicati di valore 
            // Se la lettera è uguale alla precedente e la precedente non è in uso
        if (i>0 && letteraX==letteraX_1 && !visited[i-1])continue;
        //Se sono qui posso usare la lettera
        visited[i]=1; //setto a 1 viseted
        NuovaParola[index]=letteraX;
        CreaSequenza(Input,NuovaParola,visited,index+1,dim);
        visited[i]=0; //setto a 0 viseted, BACKTRAKKING
    }
}




void ElaboraParole(char ListaParole[][LEN], int numParole) {
    for (int i = 0; i < numParole; i++) {
        char NuovaParola[LEN];
        int visited[LEN] = {0};
        int lunghezzaParola = strlen(ListaParole[i]);
        // Passa la parola specifica della lista
        CreaSequenza(ListaParole[i], NuovaParola, visited, 0, lunghezzaParola);
    }
}