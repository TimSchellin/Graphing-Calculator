#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H

#include "Queue.h"
#include "Stack.h"
#include "Token.h"
#include "Operator.h"
#include <iostream>

Queue<Token*> postfixQueue;
Queue<Token*> shuntingYard(Queue<Token*>& infixQueue) {

	Stack<Operator*> operatorStack;

	int i = 1;
	while (!infixQueue.empty()) {
		Token* item = infixQueue.pop(); //take in item off the infix Queue
		if (item->getType() == 0) {		//If its an operand, push it to postfix Queue
			postfixQueue.push(item);
		}
		else if (item->getType() == 1) {
			Operator* opItem = static_cast<Operator*>(item);
			if (opItem->getSymbol() == '(') {						//if open parenthesis, push to optr stack
				operatorStack.push(opItem);
			}
			else if (opItem->getSymbol() == ')') {					//if closed parenthisis, push everything from
				while (operatorStack.top()->getSymbol() != '(') {	//the optr stack to the postfix queue until
					postfixQueue.push(operatorStack.pop());			//the open parenthesis is found
				}
				operatorStack.pop();	//remove left parenthesis from optr stack
			}
			else if (!operatorStack.empty()) {					//if its not a parenthesis, get optr precedence
				while (operatorStack.top()->getPrecedence() <= opItem->getPrecedence()) {
					postfixQueue.push(operatorStack.pop());		//while removed item has a higher precedence than top of stack
				}												//push to postfix queue and remove from optr stack
				operatorStack.push(opItem);
			}
		}
	}
	for (int i = 0; i < operatorStack.getSize(); i++) {
		postfixQueue.push(operatorStack.pop());
	}
	return postfixQueue;
}

#endif
