#include "GraphPlane.h"

/* 
	THINGS IM GONNA NEED:
	----------------------------
	- X & Y axis (vertex arrays)
	- grid of regular horizontal and vertical lines
	- labels on axis grid ticks?
	- background?
*/

GraphPlane::GraphPlane() {
	graphBackground.setPosition(GRAPH_POS);
	graphBackground.setSize(Vector2f(GRAPH_WIDTH, GRAPH_HEIGHT));
	graphBackground.setFillColor(GRAPH_COLOR);
	setAxis();
	createGridlines();
}

void GraphPlane::setOffsets(int i, int j) {
	offset.x = i;
	offset.y = j;
}

VertexArray GraphPlane::getLine(int x1, int y1, int x2, int y2, int color) {
	VertexArray line(LineStrip, 2);
	line[0] = getVertex(x1, y1, color);
	line[1] = getVertex(x2, y2, color);
	return line;
}
void GraphPlane::createGridlines() {

	int majorSpace = 80;
	int minorSpace = majorSpace / 5;
	int spaceCovered = 0;
	
	// create major horizontal gridlines
	while (spaceCovered < (Y_MAX - Y_MIN) / 2) {
		majorGridlines_horz.push_back(getLine(X_MIN, ORIGIN.y + spaceCovered, X_MAX, ORIGIN.y + spaceCovered, 0));
		majorGridlines_horz.push_back(getLine(X_MIN, ORIGIN.y - spaceCovered, X_MAX, ORIGIN.y - spaceCovered, 0));
		spaceCovered += majorSpace;
	}
	spaceCovered = 0;

	// create major vertical gridlines
	while (spaceCovered < X_MAX / 2) {
		spaceCovered += majorSpace;
		majorGridlines_vert.push_back(getLine(ORIGIN.x + spaceCovered, Y_MIN, ORIGIN.x + spaceCovered, Y_MAX, 0));
		majorGridlines_vert.push_back(getLine(ORIGIN.x - spaceCovered, Y_MIN, ORIGIN.x - spaceCovered, Y_MAX, 0));
	}
	spaceCovered = 0;

	// create minor horizontal gridlines
	while (spaceCovered < (Y_MAX-Y_MIN) / 2) {
		minorGridlines_horz.push_back(getLine(X_MIN, ORIGIN.y + spaceCovered, X_MAX, ORIGIN.y + spaceCovered, 2));
		minorGridlines_horz.push_back(getLine(X_MIN, ORIGIN.y - spaceCovered, X_MAX, ORIGIN.y - spaceCovered, 2));
		spaceCovered += minorSpace;
	}
	spaceCovered = 0;

	// create minor vertical gridlines
	while (spaceCovered < X_MAX / 2) {
		spaceCovered += minorSpace;
		minorGridlines_vert.push_back(getLine(ORIGIN.x + spaceCovered, Y_MIN, ORIGIN.x + spaceCovered, Y_MAX, 2));
		minorGridlines_vert.push_back(getLine(ORIGIN.x - spaceCovered, Y_MIN, ORIGIN.x - spaceCovered, Y_MAX, 2));
	}
}

void GraphPlane::updateAxis() {
	// not implemented
}

void GraphPlane::setAxis() {

	xAxis.setPrimitiveType(LineStrip);
	yAxis.setPrimitiveType(LineStrip);

	xAxis.resize(2);
	yAxis.resize(2);

	xAxis[0] = getVertex(ORIGIN.x - MID_WIDTH, ORIGIN.y, 1);
	xAxis[1] = getVertex(ORIGIN.x + MID_WIDTH, ORIGIN.y, 1);

	yAxis[0] = getVertex(ORIGIN.x, BANNER_HEIGHT, 1);
	yAxis[1] = getVertex(ORIGIN.x, WINDOW_HEIGHT, 1);
}

Vertex GraphPlane::getVertex(int i, int j, int option = 0) {
	if (option == 1) {
		return Vertex(Vector2f(i, j), AXIS_COLOR);
	}
	else if (option == 0) {
		return Vertex(Vector2f(i, j), GRID_COLOR);
	}
	else return Vertex(Vector2f(i, j), M_GRID_COLOR);
}

void GraphPlane::draw(RenderWindow& window) {
	window.draw(graphBackground);

	for (int i = 0; i < majorGridlines_horz.size(); i++) {
		window.draw(majorGridlines_horz[i]);
	}

	for (int i = 0; i < majorGridlines_vert.size(); i++) {
		window.draw(majorGridlines_vert[i]);
	}

	for (int i = 0; i < minorGridlines_horz.size(); i++) {
		window.draw(minorGridlines_horz[i]);
	}

	for (int i = 0; i < minorGridlines_vert.size(); i++) {
		window.draw(minorGridlines_vert[i]);
	}

	window.draw(xAxis);
	window.draw(yAxis);

	//offset += offset;
}