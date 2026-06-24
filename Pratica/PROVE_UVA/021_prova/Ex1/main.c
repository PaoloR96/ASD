#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

#define MAX_INPUT 1000 

int main() {
    char memoria_input[MAX_INPUT][256];
    int contatore = 0;

    // --- PRIMO WHILE: INSERIMENTO ---
    printf("SAMPLE INPUT:\n");
    // Legge tutto l'input e lo salva nell'array
    while (scanf("%s", memoria_input[contatore]) != EOF) {
        contatore++;
        if (contatore >= MAX_INPUT) break;
    }

    // --- SECONDO WHILE: ELABORAZIONE ---
    printf("\nSAMPLE OUTPUT:\n");
    
    struct Node *root = NULL;
    bool errore_duplicato = false;
    int i = 0;

    while (i < contatore) {
        char *token = memoria_input[i];

        // Caso fine albero
        if (strcmp(token, "()") == 0) {
            if (!errore_duplicato && root != NULL) {
                StampaLevelOrder(root);
            } else {
                printf("not complete\n");
            }

            LiberaAlbero(root);
            root = NULL;
            errore_duplicato = false;
        } 
        else {
            // Estraiamo i dati direttamente
            int val;
            char path[256] = "";
            
            // Eseguiamo il parsing direttamente senza l'if di controllo
            // sscanf leggerà i valori e li metterà in 'val' e 'path'
            sscanf(token, "(%d,[^)]", &val, path);

            // Inizializzazione radice se l'albero è nuovo
            if (root == NULL) {
                root = malloc(sizeof(struct Node));
                root->assegnato = false;
                root->left = root->right = NULL;
            }

            // Creazione e inserimento usando la tua logica
            struct Node *temp = CreaNodo(val, path);
            
            // Se InserisciNodo restituisce false (duplicato), attiviamo l'errore
            if (!InserisciNodo(root, temp)) {
                errore_duplicato = true;
            }
            
            free(temp);
        }
        i++;
    }

    printf("\n");
    system("pause");
    return 0;
}