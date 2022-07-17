#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include "pilha.h"
#include "lista.h"
#include "ConvertInfix.h"

#define CHAR_LENGTH_LIMIT 10

int main() {
    int i = 0;
    // pilha *s = malloc(sizeof(pilha));
    pilha opstack;
    lista characters;
    lista saida;
    char expresssion[CHAR_LENGTH_LIMIT+1];

    criaPilhaVazia(&opstack);
    criarListaVazia(&characters);
    criarListaVazia(&saida);

    printf("Digite a expressao\n");
    scanf("%s",expresssion);

    while (expresssion[i] != NULL) {
        //empilha(&opstack, i);
        inserirFinal(&characters, expresssion[i]);
        printf("Inserido na lista %c\n", expresssion[i]);
        i++;
    }

    //separando caracteres
    Nodo *aux = characters.primeiro;
    while (aux != NULL) {
        if (isOperand(aux->item) == 1){
            inserirFinal(&saida, aux->item);
        }
        else if (aux->item == '('){
            empilha(&opstack, aux->item);
        }        
        else if (aux->item == ')'){
            shouldMoveExpressionBetweenParenthesis(&opstack, &saida);
        }
        else if (isOperator(aux->item)==1){
            shouldMoveGreaterPrecendenceOrStack(aux, &opstack, &saida);
        }
        aux = aux->prox;
    }
    shouldMoveRestOfStack(&opstack, &saida);
    imprimirLista(&saida);

    // while (!pilhaVazia(&s)) {
    //     i = desempilha(&s);
    //     printf("Desempilhou %d\n", i);
    // }

    // apagaPilha(&s);
    //free(s);
}

void shouldMoveExpressionBetweenParenthesis(pilha* stack, lista* list){
    char removedItem = desempilha(stack);
    while('(' != removedItem){
        inserirFinal(list, removedItem);
        removedItem = desempilha(stack);
    }
}

void shouldMoveGreaterPrecendenceOrStack(Nodo* currentNode, pilha* stack, lista* list){
    if(stack->topo == NULL){
        empilha(stack, currentNode->item);
    }else{
        while(precedenceOrder(stack->topo->item) >= precedenceOrder(currentNode->item)){
            char removedItem = desempilha(stack);
            inserirFinal(list, removedItem);
        }
        empilha(stack, currentNode->item);
    }
}

void shouldMoveRestOfStack(pilha* stack, lista* list){
    while(pilhaVazia(stack) != 1){
        char removedItem = desempilha(stack);
        inserirFinal(list, removedItem);
    }
}


int isOperand(char c){
    return isOperator(c)!=1 &&
            c != '(' &&
            c != ')';
}

int precedenceOrder(char c){
    int isOp = -1;
    if(c == '=')
        isOp = 0;
        
    else if(c == '^')
        isOp = 3;
        
    else if(c == '%')
        isOp = 2;
        
    else if(c == '*')
        isOp = 2;
        
    else if(c == '/')
        isOp = 2;
        
    else if(c == '+')
        isOp = 1;
        
    else if(c == '-')
        isOp = 1;

    return isOp;
}

int isOperator(char c){
    return precedenceOrder(c) > 0;
}
