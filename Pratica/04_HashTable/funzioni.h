#ifndef FUNZIONI_H
#define FUNZIONI_H
typedef struct entry{
    char *key;
    char *value;
    struct entry *next; //serve a collegare un’altra scheda nello stesso cassetto (in caso di collisione)
}entry_t;
typedef struct HashTable{
     int size;             // quanti "cassetti" ha
      entry_t **buckets;    // array di liste (uno per cassetto)
}hashtable_t;
/*metodi*/
unsigned int hash(const char *key, int size);
hashtable_t *ht_create(int size);
void ht_insert(hashtable_t *table, const char *key, const char *value);
void ht_print(hashtable_t *table);
char *ht_search(hashtable_t *table, const char *key);
void ht_delete(hashtable_t *table, const char *key, const char *value);

#endif
