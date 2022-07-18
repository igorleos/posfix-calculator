#include "lista.h"
#include<stdio.h>
#include<stdlib.h>
void criarListaVazia(lista *l) {
    l->primeiro = NULL ;
    l->ultimo = NULL ;
}

char listaVazia(lista * l) {
    return l->primeiro == NULL ;
}

void inserirInicio(lista *l, char x ) {
    Nodo *novo = malloc(sizeof(Nodo));
    novo->item = x;
    novo->prox = l->primeiro;
    if (l->primeiro == NULL) 
        l->ultimo = novo;
    l->primeiro = novo;
}

void inserirFinal(lista *l, char x) {
    Nodo *novo = malloc(sizeof(Nodo)) ;
    novo->item = x ;
    novo->prox = NULL ;
    if (l->primeiro == NULL ) 
        l->primeiro = novo ;
    else 
        l->ultimo->prox = novo ;    
    l->ultimo = novo ;
}

Nodo *buscarPosicao(lista *l, char p) {
    Nodo *aux = l->primeiro;
    char c = 1;
    while ( aux != NULL && c < p ) {
        aux = aux->prox;
        c ++;
    }
    return aux;
}

void inserirPosicao(lista *l, char x, char p) {
    if (p == 1)
        inserirInicio(l, x);
    else {
        Nodo *anterior = l->primeiro, *posterior;
        Nodo *novo = malloc(sizeof(Nodo));
        novo->item = x ;
        anterior = buscarPosicao(l ,p -1);
        posterior = anterior->prox;
        anterior->prox = novo ;
        novo->prox = posterior;
        if (posterior == NULL)
            l->ultimo = novo;
    }
}

char removerInicio(lista * l) {
    Nodo * aux;
    char x = -1;
    if (listaVazia(l) )
        printf("Lista Vazia\n");
    else {
        aux = l->primeiro;
        x = aux->item;
        l->primeiro = l->primeiro->prox;
        if (l->primeiro == NULL)
           l->ultimo = NULL;
        aux->prox = NULL;
        free(aux);
    }
    return x;
}

char removerFinal(lista *l) {
    char x = -1;
    Nodo *aux = NULL , *anterior  = NULL;
    if ( listaVazia(l))
        printf("Lista Vazia\n");
    else if (l->primeiro == l->ultimo) {
        aux = l->primeiro;
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    else {
        anterior = l->primeiro;
        while (anterior->prox != l->ultimo)
            anterior = anterior->prox;
        aux = l->ultimo;
        anterior->prox = NULL;
        l->ultimo = anterior;
    }
    x = aux->item;
    aux->prox = NULL ;
    free(aux) ;
    return x ;
}

char removerPosicao(lista *l, char p) {
    char x = -1;
    Nodo *anterior, *posterior, *aux;
    if (p==1)
        x = removerInicio(l);
    else {    
        anterior = buscarPosicao(l,p-1);
        aux = anterior->prox;
        posterior = aux->prox;
        anterior->prox = posterior;
        if (aux == l->ultimo)
            l->ultimo = anterior;
        x = aux->item;
        aux->prox = NULL;
        free(aux);
    }
    return x;    
}	

void apagarLista(lista *l) {
    Nodo *aux = l->primeiro;
    while (aux != NULL) {
        l->primeiro = l->primeiro->prox;
        free(aux);   
        aux = l->primeiro;
    }
}

void imprimirLista(lista *l) {
    Nodo *aux = l->primeiro;
    while (aux != NULL) {
        printf("%C ", aux->item);
        aux = aux->prox;
    }
    printf("\n");
}
