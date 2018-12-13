#ifndef OPERATOR_H
#define OPERATOR_H

#include "Token.h"

class Operator :
	public Token
{
public:
	Operator() : Token(1) {
		//cout << "Operator constructor called\n";
	}

	Operator(char symb) : Token(1) {
		symbol = symb;
		//cout << "Operator constructor called\n";
	}

	~Operator() {
		//cout << "Operator destructor called\n";
	}

	void print(ostream& outs = cout) const {
		cout << symbol;
	}
	
	char getSymbol() {
		return symbol;
	}

	void setSymbol(char symb) {
		symbol = symb;
	}

	double calculate(double left, double right) {

		switch (symbol) {
			case '+':
				return(left + right);
			case '-':
				return(left - right);
			case '*':
				return(left * right);
			case '/':
				return(left / right);
			case '^':
				double result = left;
				for (int i = 0; i < right-1; i++) {
					result *= result;
				}
				return result;
		}
	}

	int getPrecedence() {
		if(symbol == '+' || symbol == '-'){
			return 0;
		}
		if (symbol == '*' || symbol == '/') {
			return 1;
		}
		if (symbol == '^') {
			return 2;
		}
	}

private:
	char symbol;
};

#endif
