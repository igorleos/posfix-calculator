#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include "pilha.h"
#include "lista.h"
#include "PosfixParser.h"


void infixToPosfix(char* infix) {
    lista infixList;
    lista posfixList;
    char expresssion[CHAR_LENGTH_LIMIT+1];

    strcpy(expresssion, infix);

    criarListaVazia(&infixList);
    criarListaVazia(&posfixList);

    //Preenchendo a lista de caracteres da expressao infix
    fillInfixList(expresssion, &infixList);

    //Fazendo a conversão para posfix
    doParsing(&infixList, &posfixList);

    imprimirLista(&posfixList);

    clearLists(&infixList, &posfixList);
}

void doParsing(lista* infixList, lista* posfixList){
    pilha opstack;
    criaPilhaVazia(&opstack);
    Nodo *aux = infixList->primeiro;

    while (aux != NULL) {
        printf("\npilha:\n");
        imprimirPilha(&opstack);        
        printf("\nlista:\n");
        imprimirLista(posfixList);
        if (isOperand(aux->item) == 1){
            inserirFinal(posfixList, aux->item);
        }
        else if (aux->item == '('){
            empilha(&opstack, aux->item);
        }        
        else if (aux->item == ')'){
            shouldMoveExpressionBetweenParenthesis(&opstack, posfixList);
        }
        else if (isOperator(aux->item)==1){
            shouldMoveGreaterPrecendenceOrStack(aux, &opstack, posfixList);
        }
        aux = aux->prox;
    }
    shouldMoveRestOfStack(&opstack, posfixList);
    clearStackAndNode(&opstack, aux);
}

void fillInfixList(char string[], lista* list){
    int i = 0;
    while (string[i] != '\0') {
        inserirFinal(list, string[i]);
        i++;
    }
}

void shouldMoveExpressionBetweenParenthesis(pilha* stack, lista* list){
    char removedItem = desempilha(stack);
    while('(' != removedItem){
        inserirFinal(list, removedItem);
        removedItem = desempilha(stack);
    }
}

void shouldMoveGreaterPrecendenceOrStack(Nodo* currentNode, pilha* stack, lista* list){
    while(precedenceOrder(stack->topo->item) >= precedenceOrder(currentNode->item)){
        char removedItem = desempilha(stack);
        inserirFinal(list, removedItem);
    }
    empilha(stack, currentNode->item);
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

void clearLists(lista* infixList, lista* posfixList){
    while (!listaVazia(infixList)) {
       removerInicio(infixList);
    }
    while (!listaVazia(posfixList)) {
       removerInicio(posfixList);
    }
    apagarLista(infixList);
    apagarLista(posfixList);
}

void clearStackAndNode(pilha* stack, Nodo* auxNode){
    while (!pilhaVazia(stack)) {
        desempilha(stack);
    }
    apagaPilha(stack);
    free(auxNode);
}