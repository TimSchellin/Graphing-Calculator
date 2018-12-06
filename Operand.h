#ifndef OPERAND_H
#define OPERAND_H

#include "Token.h"

class Operand:
	public Token
{
public:

	Operand() : Token(0) {
		//cout << "Operand constructor called\n";
	}

	Operand(double number) : Token(0) {
		num = number;
		//cout << "Operand constructor called\n";
	}

	~Operand() {
		//cout << "Operand destructor called\n";
	}

	void print(ostream& outs = cout) const {
		outs << num;
	}

	double getNum() {
		return num;
	}

private:
	double num;
};

#endif