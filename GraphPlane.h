#ifndef GRAPHPLANE_H
#define GRAPHPLANE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Coordinates.h"
#include "Dimensions.h"
#include <vector>

using namespace sf;
using namespace std;

class GraphPlane
{
public:
	GraphPlane();
	~GraphPlane() {}

	void draw(RenderWindow& window);
	void setOffsets(int x, int y);
	void updateAxis();
	void setAxis();
	void createGridlines();
	VertexArray getLine(int x1, int y1, int x2, int y2, int color);
	Vertex getVertex(int i, int j, int option );

private:

	vector<VertexArray> majorGridlines_horz;
	vector<VertexArray> majorGridlines_vert;

	vector<VertexArray> minorGridlines_horz;
	vector<VertexArray> minorGridlines_vert;

	Vector2f offset;
	
	//VertexArray testGrid;
	VertexArray xAxis;
	VertexArray yAxis;
	RectangleShape graphBackground;
};

#endif
