#ifndef __Nodo_H_
#define __Nodo_H_

typedef struct Nodo_t {
    char item;
    long double longItem;
    struct Nodo_t *prox;
} Nodo;

#endif //__Nodo_H_
