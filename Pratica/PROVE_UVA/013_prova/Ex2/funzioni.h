#ifndef FUNZIONI_H
#define FUNZIONI_H
#include <stdbool.h>
#define TEST 1000
#define R 8
typedef struct {
    int S[R]; 
}CasoTest;


void RiempiCasiTest(int S[R]);
void PosizioneRegina(int Sequenza[R],int posizioneRegina[R],int colonna);
bool controlliVerificati(int posizioneRegina[], int colonna, int riga);
int Compara(int S[R], int P[R]);

#endif
