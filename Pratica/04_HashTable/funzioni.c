#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"  // Include il file header
unsigned int hash(const char *key, int size) {
    unsigned long hash = 5381;
    int c;
    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    return hash % size;
}
hashtable_t *ht_create(int size){
        hashtable_t *table= malloc(sizeof(hashtable_t)); //creo la tabella
        table->size=size;   //definisco la dim
        table->buckets=calloc(size,sizeof(entry_t*));   //inizializzo con una calloc a 0 tutti elementi del bucket
        return table;
}
void ht_insert(hashtable_t *table, const char *key, const char *value){
        unsigned int index=hash(key,table->size);
        entry_t * new_entry=malloc(sizeof(entry_t));
        new_entry->key=strdup(key);
        new_entry->value=strdup(value);
       new_entry->next = table->buckets[index];  // collega il nodo alla lista esistente
       table->buckets[index] = new_entry;        // aggiorna il cassetto con il nuovo nodo
}
void ht_print(hashtable_t *table) {
    printf("\n--- Contenuto della tabella hash ---\n");
    for(int i=0;i<table->size;i++){
         printf("Cassetto[%d]: ", i);
        entry_t *entry = table->buckets[i];
        if(entry==NULL){
             printf("vuoto\n");
        }else{
            while(entry!=NULL){
                 printf("(%s -> %s)", entry->key, entry->value);
                 if (entry->next != NULL) printf(" -> ");
                 entry = entry->next;
            }
            printf("\n");
        }

    }
}
char *ht_search(hashtable_t *table, const char *key){
    unsigned int index = hash(key, table->size);
    entry_t *entry = table->buckets[index];
    int found = 0;

    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            printf("%s -> %s\n", entry->key, entry->value);
            found = 1;
        }
        entry = entry->next;
    }

    if (!found)
        printf("Chiave '%s' non trovata.\n", key);
}


void ht_delete(hashtable_t *table, const char *key, const char *value) {
    unsigned int index = hash(key, table->size);
    entry_t *entry = table->buckets[index];
    entry_t *prev = NULL;
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0 && strcmp(entry->value, value) == 0) {
            // Nodo trovato: rimuovilo
            if (prev == NULL) {
                // Primo nodo della lista
                table->buckets[index] = entry->next;
            } else {
                // Nodo in mezzo o in fondo
                prev->next = entry->next;
            }
            printf("Rimosso: (%s -> %s)\n", key, value);
            free(entry->key);
            free(entry->value);
            free(entry);
            return; // esci dopo la rimozione
        }

        // Passa al prossimo nodo
        prev = entry;
        entry = entry->next;
    }

    printf("Nessun elemento (%s -> %s) trovato.\n", key, value);
}