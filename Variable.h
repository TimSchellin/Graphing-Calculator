#pragma once
#include "Token.h"
class Variable :
	public Token
{
public:
	Variable() : Token(3) {}

	void print(ostream& outs = cout) const {
		outs << var;
	}

	~Variable() {}

private:
	char var = 'x';
};

