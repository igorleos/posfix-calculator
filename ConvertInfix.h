#ifndef __ConvertInfix_H_
#define __ConvertInfix_H_

int isOperator(char c);
int isOperand(char c);
int precedenceOrder(char c);
void shouldMoveExpressionBetweenParenthesis(pilha* stack, lista* list);
void shouldMoveGreaterPrecendenceOrStack(Nodo* currentNode, pilha* stack, lista* list);
void shouldMoveRestOfStack(pilha* stack, lista* list);

#endif //__ConvertInfix_H_
