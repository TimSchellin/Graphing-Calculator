#ifndef FUNCTION_OPERATOR_H
#define FUNCTION_OPERATOR_H

#include "Operand.h"
#include "Token.h"
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


class FunctionOperator : public Token {

public:
	FunctionOperator() : Token(2) {}
	FunctionOperator(string inputFunction) : Token(2) {
		str = inputFunction;
	}

	void print(ostream& outs = cout) const {
		outs << str;
	}
	double calculate(double input);

	int getPrecedence();

private:
	string str;
};

/*
STRING POSSIBLE OPTIONS:
	sin   sine    cos    cosine    tan    tangent    sec   secant    csc    cosecant    cot    cotangent
	arcsin    arcsine
	potato



*/

#endif