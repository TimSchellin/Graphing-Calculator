#ifndef STRINGTOQUEUE_H
#define STRINGTOQUEUE_H

#include "Queue.h"
#include "Stack.h"
#include "Token.h"
#include "Operand.h"
#include "Operator.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include "FunctionOperator.h"

using namespace std;

//prototypes
bool isNumber(char);
bool isSymbol(char);

Queue<Token*> infixExpression;

Queue<Token*>& convert(string inputString) {

	string doubleNum = "";
	string functionString = "";

	for (int i = 0; i < inputString.size(); i++) {
		if (isNumber(inputString[i])) {
			doubleNum += inputString[i];
			if (i == inputString.size() || !isNumber(inputString[i + 1])) {
				infixExpression.push(new Operand(stod(doubleNum)));
				doubleNum = "";
			}
		}
		else if (isalpha(inputString[i])) {
			functionString += inputString[i];
			if (i == inputString.size() || !isalpha(inputString[i + 1])) {
				infixExpression.push(new FunctionOperator(functionString));
				functionString = "";
			}
		}
		else if (isSymbol(inputString[i])){
			infixExpression.push(new Operator(inputString[i]));
		}
	}
	return infixExpression;
}

bool isNumber(char testChar) {
	if (isdigit(testChar) || testChar == '.') return true;
	else return false;
}

bool isSymbol(char testChar) {
	if (!isNumber(testChar) && !isalpha(testChar)) return true;
	else return false;
}

#endif