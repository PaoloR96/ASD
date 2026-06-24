#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

void stampaDizionario(Dizionario d) {
    for (int i = 0; i < d.n; i++) printf("%s\n", d.parola[i]);
    for (int i = 0; i < d.m; i++) printf("%s\n", d.regole[i]);
}

void ElaboraPassword(Dizionario d, int indexRegola, char regola_corrente[], char password_accumulata[]) {
        // CASO BASE: Se l'indice ha raggiunto la fine della regola, la password è completa
        if(indexRegola==strlen(regola_corrente)){
            printf("%s\n", password_accumulata);
            return;   
        }
        // Prendiamo il carattere corrente della regola
        char carattere_attuale = regola_corrente[indexRegola];
        //CASO PAROLA #
        if (carattere_attuale == '#') {
            for (int i = 0; i < d.n; i++) {
                    char prossima_password[512];
                    // Copiamo la parte già costruita
                    strcpy(prossima_password, password_accumulata);
                    // Aggiungiamo la parola i-esima del dizionario
                    strcat(prossima_password,d.parola[i]);
                    // Ricorsione per il prossimo simbolo della regola
                    ElaboraPassword(d,indexRegola+1,regola_corrente,prossima_password);
            }
        }
        //CASO PAROLA 0
        else if (carattere_attuale == '0'){
            for (int i = 0; i < 10; i++) {
                char prossima_password[512];
                char cifra_temp[2];   
                strcpy(prossima_password, password_accumulata);
                // Trasformiamo il numero i nel carattere corrispondente ('0'-'9')
                cifra_temp[0] = i + '0'; 
                cifra_temp[1] = '\0';
                strcat(prossima_password, cifra_temp);
                // Ricorsione per il prossimo simbolo della regola
                ElaboraPassword(d, indexRegola + 1, regola_corrente, prossima_password);
            }
        }
}