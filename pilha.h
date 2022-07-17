
#ifndef __pilha_H_
#define __pilha_H_

#include "Nodo.h"

typedef struct {
    Nodo *topo;
    Nodo *fundo;
} pilha;

void criaPilhaVazia(pilha *s);

int pilhaVazia (pilha *s);

void empilha (pilha *s , char x);

char desempilha(pilha *s);

void apagaPilha (pilha *s);

#endif //__pilha_H_
