#include "UserFunction.h"
#include <cmath>
//#include "StringToShunting.h";
#include <string>
#include <iostream>
//#include "StringToQueue.h"
//#include "ShuntingYard.h"
/*
	THINGS IM GONNA NEED:
	----------------------------
	- color for each function!
	- an array of visual elements
	- the function itself
*/


UserFunction::UserFunction(){
	getPlot();
}

UserFunction::UserFunction(String input) {
	getPlot();
	functionStr = input;

}

void UserFunction::draw(RenderWindow& window) {
	getPlot();
	window.draw(plot);
}

void UserFunction::getPlot() {
	plot.setPrimitiveType(PrimitiveType::LinesStrip);
	plot.resize(GRAPH_WIDTH);
	for (float i = (X_MIN-OFFSET.x); i < (X_MAX-OFFSET.x); i++) { 
		plot.append(Vertex(Vector2f((i + OFFSET.x), (getY(i+OFFSET.x)+OFFSET.y)), CURVE_COLOR));
	}
}

float UserFunction::getY(float x) {
	x = ((x - (BAR_WIDTH + GRAPH_WIDTH / 2))-OFFSET.x);
	x = x / (GRID_RATIO*YSCALE);
	float y = (-1*(tan(x*x)));//convertCalc(functionStr, x);
	y *= GRID_RATIO*YSCALE;
	y = getRealPos(y);
	return (y-1);
}

float UserFunction::getRealPos(float y) {
	return (WINDOW_HEIGHT - (y + (GRAPH_HEIGHT / 2)) - 1);
	//do stuff
}


