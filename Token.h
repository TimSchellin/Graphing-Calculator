#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
using namespace std;

class Token
{
public:

	Token(int num):type(num) {
		//cout << "Token constructor called";
	}

	~Token() {
		//cout << "Token destructor called";
	}
	
	void virtual print(ostream& outs = cout) const {}
	double virtual getNum() { return 0;  }
	char virtual getSymbol() { return ' '; }
	int virtual getPrecedence() { return 0; }

	/*
	friend ostream& operator << (ostream& outs, const Token* p) {
		//p->print();
		return outs;
	}
	*/

	int getType() {
		return type;
	}

	void setType(int i) {
		type = i;
	}

private:
	int type;
};

#endif
