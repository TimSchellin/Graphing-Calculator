#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H

#include "Queue.h"
#include "Stack.h"
#include "Token.h"
#include "Operator.h"
#include <iostream>
#include "FunctionOperator.h"

Queue<Token*> postfixQueue;
Queue<Token*> shuntingYard(Queue<Token*>& infixQueue) {
	//cout << "am i not shunting???\n";
	Stack<Token*> operatorStack;

	// assert there are no variables

	int i = 1;
	while (!infixQueue.empty()) {
		Token* item = infixQueue.pop(); //take in item off the infix Queue

		//cout << "\ntype: " << item->getType();
		if (item->getType() == 1 || item->getType() == 2) {
			if (item->getType() == 2) {
				FunctionOperator* opItem = static_cast<FunctionOperator*>(item);
				operatorStack.push(opItem);
			}
			else {
				//cout << "YOU QUALIFY\n";
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
				//here does not allow the first operator to be pushed onto the stack unless parenthsis
				else if (!operatorStack.empty()) {					//if its not a parenthesis, get optr precedence
					while (operatorStack.top()->getPrecedence() <= opItem->getPrecedence()) {
						postfixQueue.push(operatorStack.pop());		//while removed item has a higher precedence than top of stack
					}												//push to postfix queue and remove from optr stack
					operatorStack.push(opItem);
				}
				else {
					operatorStack.push(opItem);
				}
			}
		}
		else postfixQueue.push(item);
	}
	while(!operatorStack.empty()) {
		postfixQueue.push(operatorStack.pop());
	}
	return postfixQueue;
}

#endif
