#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void InitNode(Node* node, int val) {
    node->value = val;
    node->next = NULL;
}