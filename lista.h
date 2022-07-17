#ifndef __lista_H_
#define __lista_H_

#include "Nodo.h"
typedef struct {
    Nodo *primeiro ;
    Nodo *ultimo ;
} lista ;

void criarListaVazia(lista *l);
char listaVazia(lista * l);
void inserirInicio(lista *l , char x);
void inserirFinal(lista *l, char x);
Nodo *buscarPosicao(lista *l, char p);
void inserirPosicao(lista *l, char x, char p);
char removerInicio(lista * l);
char removerFinal(lista *l);
char removerPosicao(lista *l, char p);
void apagarLista(lista *l);
void imprimirLista(lista *l);

#endif //__lista_H_