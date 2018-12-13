#ifndef RPN_H
#define RPN_H

#include "Operand.h"
#include "Operator.h"
#include "Stack.h"
#include "Queue.h"
//#include "ShuntingYard.h"
//#include "StringToQueue.h"
#include "FunctionOperator.h"
#include "Variable.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


double RPN(Queue<Token*> tokenQueue, double x_input) {
	Stack <double> tokenStack;
	//int size = tokenQueue.getSize();

	while (!tokenQueue.empty()) {
		Token* token = tokenQueue.pop();
		if (token->getType() == 3) {
			token = new Operand(x_input);
		}
		//token->print();
		//cout << "\n";
		if (token->getType() == 1) {
			Operator* optr = static_cast<Operator*>(token);
			double left = tokenStack.pop();
			double right = tokenStack.pop();
			tokenStack.push(optr->calculate(left, right));
		}

		if (token->getType() == 2) {
			FunctionOperator* foptr = static_cast<FunctionOperator*>(token);
			double f = tokenStack.pop();
			tokenStack.push(foptr->calculate(f));
		}
		else if (token->getType() == 0) {
			tokenStack.push(token->getNum());
		}

		cout << "\ntop: " << tokenStack.top();
	}
	return tokenStack.pop();
}

#endif