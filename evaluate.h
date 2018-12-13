#define EVALUATE_H
#ifndef EVALUATE_H

#include <iostream>
#include <cmath>
#include <cassert>
#include "Operand.h"
#include "Operator.h"


double evaluate(Token lhs, Token  rhs, Token optr) {
	assert(optr.getType() == 1); //make sure 1 is for operators, and not operands
	switch (optr.getSymbol()) {
		case '+':
			return(lhs.getNum() + rhs.getNum());
		case '-':
			return(lhs.getNum() - rhs.getNum());
		case '*':
			return(lhs.getNum() * rhs.getNum());
		case '/':
			return(lhs.getNum() / rhs.getNum());
		case '^':
			double result = lhs.getNum();
			for (int i = 0; i < rhs.getNum(); i++) {
				result *= result;
			}
			return result;
	}
}

#endif