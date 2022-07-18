#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include "pilha.h"
#include "lista.h"
#include "PosfixCalculator.h"


void calculate(char expression[]) {
    lista auxList;
    lista posfixList;

    criarListaVazia(&auxList);
    criarListaVazia(&posfixList);

    //Preenchendo a lista de caracteres da expressao infix
    fillInfixList(expression, &auxList);
    
    //Fazendo a calculo 
    doCalc(&auxList);

    clearLists(&auxList, &posfixList);
}

void doCalc(lista* auxList){
    pilha operandStack;
    criaPilhaVazia(&operandStack);
    Nodo *auxNode = auxList->primeiro;

    while (auxNode != NULL) {
        if (isOperand(auxNode->item) == 1){
            long double x;
            sscanf(&auxNode->item, "%Lf", &x);
            empilhaLong(&operandStack, x);
        }
        else if (isOperator(auxNode->item)==1){
            long double secondValue = desempilhaLong(&operandStack);
            long double firstValue = desempilhaLong(&operandStack);
            long double result = getSubExpressionResult(firstValue, secondValue, auxNode->item);
            empilhaLong(&operandStack, result);
        }  
        auxNode = auxNode->prox;
    }
    imprimirPilhaLong(&operandStack);
    clearStackAndNode(&operandStack, auxNode);
}

void fillInfixList(char string[], lista* list){
    int i = 0;
    while (string[i] != '\0') {
        inserirFinal(list, string[i]);
        i++;
    }
}

long double doPow(long double base, long double _expo){
    long double result = 1;
    while (_expo != 0 ) {
        result *= base;
        --_expo;
    }
    return result;
}

int isOperand(char c){
    return isOperator(c)!=1 &&
            c != '(' &&
            c != ')';
}

long double getSubExpressionResult(long double firstValue, long double secondValue, char operand){
    long double result = 0.0;
    if(operand ==  '=')
        result = 0;
        
    else if(operand ==  '^'){
        result = doPow(firstValue, secondValue);
    }
        
    else if(operand ==  '%')
        result = (int)firstValue % (int)secondValue;
        
    else if(operand ==  '*')
        result = firstValue * secondValue;
        
    else if(operand ==  '/')
        result = firstValue / secondValue;
        
    else if(operand ==  '+')
        result = firstValue + secondValue;
        
    else if(operand ==  '-')
        result = firstValue - secondValue;
    else
        printf("");
    return result;
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

void clearLists(lista* auxList, lista* posfixList){
    while (!listaVazia(auxList)) {
       removerInicio(auxList);
    }
    while (!listaVazia(posfixList)) {
       removerInicio(posfixList);
    }
    apagarLista(auxList);
    apagarLista(posfixList);
}

void clearStackAndNode(pilha* stack, Nodo* auxNode){
    while (!pilhaVazia(stack)) {
        desempilha(stack);
    }
    apagaPilha(stack);
    free(auxNode);
}