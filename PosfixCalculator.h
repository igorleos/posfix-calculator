#ifndef __PosfixCalculator_H_
#define __PosfixCalculator_H_
#include "pilha.h"
#include "lista.h"
#define CHAR_LENGTH_LIMIT 100

void calculate(char infix[]);
void fillInfixList(char string[], lista* list);
void doCalc(lista* infixList);

long double getSubExpressionResult(long double firstValue, long double secondValue, char operand);
long double doPow(long double base, long double _expo);

int isOperator(char c);
int isOperand(char c);
int precedenceOrder(char c);

void clearLists(lista* infixList, lista* posfixList);
void clearStackAndNode(pilha* stack, Nodo* auxNode);

#endif //__PosfixCalculator_H_
