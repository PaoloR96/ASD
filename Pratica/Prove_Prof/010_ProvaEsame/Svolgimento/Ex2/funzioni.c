#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

Risultato RicercaBinaria(int Tempo[MAX], int dim, Intervallo Window)
{
    //1.Inizializza il risultato:
    Risultato risLocale = {Window, 0};
    //Setto low ed high
    int low = 0;
    int high = dim - 1;
    int mid;
    // Conterrà l'indice del primo elemento >= Window.start
    int primo = -1;
    // Conterrà l'indice dell'ultimo elemento <= Window.end
    int ultimo = -1;

    //2.Ricerca del primo elemento>= Window.start
    while(low <= high){
        // Calcolo del punto medio forma sicura che evita overflow
        mid = low + (high - low) / 2;
        // Se il valore trovato è valido
        if(Tempo[mid] >= Window.start){
            // Salvo l'indice
            primo = mid;
            // Continuo a cercare a sinistra perché potrebbe esistere un indice minore
            high = mid - 1;
        }else{
            // Il valore è troppo piccolo,cerco nella metà destra
            low = mid + 1;
        }
    }
    
    //3.Ricerca dell'ultimo elemento <= Window.end
    // Reinizializzo i limiti
    low = 0;
    high = dim - 1;
    while(low <= high){
        mid = low + (high - low) / 2;
        // Se il valore è dentro il limite superiore
        if(Tempo[mid] <= Window.end){
            // Salvo l'indice
            ultimo = mid;
            // Continuo più a destra perché potrebbe esistere un indice maggiore
            low = mid + 1;
        }else{
            // Valore troppo grande:cerco a sinistra
            high = mid - 1;
        }
    }

    //4.Se entrambi gli indici sono validi e l'intervallo esiste realmente
    if(primo != -1 && ultimo != -1 && primo <= ultimo){
        // Numero elementi compresi
        risLocale.numeroEventi = ultimo - primo + 1;
        //Salvo gli anni esatti del primo e dell'ultimo evento trovato,
        //altrimenti risLocale.Window.end conterrebbe il valore teorico (x+Y-1)
        risLocale.Window.start = Tempo[primo];
        risLocale.Window.end = Tempo[ultimo];
    }
    return risLocale;
}


Risultato TrovaMassimo(int Tempo[MAX], int dim, int Y){
    //1.Inizializzo le strutture dati
    Intervallo Window = {-1, -1};
    Risultato risASS = {{-1, -1}, 0};
    Risultato risTmp = {{-1, -1}, 0};
    
    for (int i = 0; i < dim; i++) {
        // Definisco il range dell'intervallo (x, x+Y-1)
        Window.start = Tempo[i];
        Window.end = Tempo[i] + Y - 1;
        risTmp = RicercaBinaria(Tempo,dim,Window);
        // Aggiorno il massimo numero di eventi con relativi indici
        if (risTmp.numeroEventi > risASS.numeroEventi)risASS = risTmp;
    }
    
    return risASS;
}


