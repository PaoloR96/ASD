#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    hashtable_t *table = ht_create(10); // creo un hashtable con  10 "cassetti"
    ht_insert(table, "a", "uno");
    ht_insert(table, "a", "undici");
    ht_insert(table, "b", "due");
    ht_insert(table, "c", "tre");
    ht_insert(table, "d", "quattro");
    ht_insert(table, "e", "cinque");
    ht_insert(table, "f", "sei");
    ht_insert(table, "g", "sette");
    ht_insert(table, "h", "otto");
    ht_insert(table, "i", "nove");
    ht_insert(table, "j", "dieci");

    ht_print(table);

   printf("Valori per la chiave 'a':\n");
   ht_search(table, "a");
   ht_delete(table, "a", "undici");
   ht_print(table);
   system("pause");

    return 0;
}
