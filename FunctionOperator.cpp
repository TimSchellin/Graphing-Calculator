#include "FunctionOperator.h"
#include <cmath>

double FunctionOperator::calculate(double input) {
	string functionString = str;
	vector<string> operations = { "sin", "sine", "cos", "cosine", "tan", "tangent" };
	vector<string>::iterator found = find(operations.begin(), operations.end(), functionString);
	int index = distance(operations.begin(), found);

	switch (index) {
	case 0: case 1:
		return sin(input);
	case 2: case 3:
		return cos(input);
	case 4: case 5:
		return tan(input);
	}
}

int FunctionOperator::getPrecedence() {
	return 0;
}