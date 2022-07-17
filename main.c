#include<stdio.h>
#include<stdlib.h>
#include "pilha.h"

int main() {
    int i = 0;
    // pilha *s = malloc(sizeof(pilha));
    pilha s;
    criaPilhaVazia(&s);
    while (i < 10) {
        empilha(&s, i);
        printf("Empilhou %d\n", i);
        i++;
    }
    while (!pilhaVazia(&s)) {
        i = desempilha(&s);
        printf("Desempilhou %d\n", i);
    }

    apagaPilha(&s);
    //free(s);
}
