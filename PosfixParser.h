#ifndef __PosfixParser_H_
#define __PosfixParser_H_
#include "pilha.h"
#include "lista.h"
#define CHAR_LENGTH_LIMIT 100

void infixToPosfix(char* infix);
void fillInfixList(char string[], lista* list);
void doParsing(lista* infixList, lista* posfixList);

void shouldMoveExpressionBetweenParenthesis(pilha* stack, lista* list);
void shouldMoveGreaterPrecendenceOrStack(Nodo* currentNode, pilha* stack, lista* list);
void shouldMoveRestOfStack(pilha* stack, lista* list);

int isOperator(char c);
int isOperand(char c);
int precedenceOrder(char c);

void clearLists(lista* infixList, lista* posfixList);
void clearStackAndNode(pilha* stack, Nodo* auxNode);

#endif //__PosfixParser_H_
