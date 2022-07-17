#ifndef __OpNodo_H_
#define __OpNodo_H_

typedef struct OpNodo_t {
    char item;
    struct OpNodo_t *prox;
} OpNodo;

#endif //__OpNodo_H_
