
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

void empilhaLong(pilha *s , long double x);

char desempilha(pilha *s);

long double desempilhaLong(pilha *s);

void apagaPilha (pilha *s);

void imprimirPilha(pilha *p);

void imprimirPilhaLong(pilha *p);

#endif //__pilha_H_
