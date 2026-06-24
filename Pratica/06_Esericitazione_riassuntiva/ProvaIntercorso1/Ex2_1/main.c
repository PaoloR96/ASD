#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
   

    int T=0,A[MAX][MAX],Size[MAX],index=0;
    printf("Sample Input:\n");
    printf("Definsci i casi di Test:");
    scanf("%d",&T);
    while (T!=0){
        scanf("%d",&Size[index]);
        RiempiVettore(A[index],Size[index]);
        index++;
        T--;
    }
    printf("Sample Output:\n");
    TrovaElemento(A,Size,index);
    
    system("pause");
    return 0;
}
