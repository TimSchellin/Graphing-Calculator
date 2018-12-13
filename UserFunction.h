
#ifndef USERFUNCTION_H
#define USERFUNCTION_H

#include "Dimensions.h"

class UserFunction
{
public:
	UserFunction();
	UserFunction(String input);
	~UserFunction() {}

	void draw(RenderWindow& window);
	float getY(float x);
	void getPlot();
	float getRealPos(float x);

private:
	VertexArray plot;
	String functionStr;
};

#endif