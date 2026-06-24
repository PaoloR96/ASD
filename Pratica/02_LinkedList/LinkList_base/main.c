#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    Node n1,n2,n3;
    InitNode(&n1, 5);
    printf("Value: %d; Next: %p\n", n1.value, (void*)n1.next);
    InitNode(&n2, 10);
    printf("Value: %d; Next: %p\n", n2.value, (void*)n2.next);
    InitNode(&n3, 15);
    printf("Value: %d; Next: %p\n", n3.value, (void*)n3.next);
    n2.next = &n1;
    printf("dopo il collegamento:\n");
    printf("n2.value: %d; n2.next: %p\n", n2.value, (void*)n2.next);
    printf("n2.next->value: %d\n", n2.next->value);

     n3.next = &n2;
    printf("dopo il collegamento:\n");
    printf("n3.value: %d; n3.next: %p\n", n3.value, (void*)n3.next);
    printf("n3.next->value: %d\n", n3.next->value);
   
   
    system("pause");
    return 0;
}
