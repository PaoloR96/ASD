#ifndef FUNZIONI_H
#define FUNZIONI_H
// Definizione struttura Stack
typedef struct {
    int value[10];   // array statico
    int count;       // numero di elementi
    int capacity;    // capacità massima (10)
} Stack;

// Prototipi delle funzioni
void initStack(Stack* s);
void StampaStack(Stack* s);
void push(Stack* s, int val);
int pop(Stack* s);

#endif
