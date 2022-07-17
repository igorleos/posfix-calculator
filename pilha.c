#include<stdio.h>
#include<stdlib.h>
#include "pilha.h"

void criaPilhaVazia(pilha *s) {
    s->topo = malloc(sizeof(Nodo));
    s->fundo = s->topo;
    s->topo->prox = NULL;
}

int pilhaVazia ( pilha * s) {
    return s->topo == s->fundo;
}

void empilha(pilha *s, char x) {
    Nodo *novo = malloc(sizeof(Nodo));
    novo->prox = s->topo;
    s->topo->item = x ;
    s->topo = novo ;
}

char desempilha(pilha *s) {
    int item = -1;
    if (pilhaVazia(s))
        printf ("Underflow : pilha vazia .\n") ;
    else {
        Nodo *aux = s->topo;
        s->topo = aux->prox ;
        item = aux->prox->item ;
        free(aux) ;
    }
    return item ;
}

void apagaPilha (pilha *s) {
    while (!pilhaVazia(s))
        desempilha(s);
    free(s->topo);
    s->topo = NULL;
    s->fundo = NULL;
}

