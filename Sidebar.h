#ifndef SIDEBAR_H
#define SIDEBAR_H


#include "Dimensions.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Sidebar
{
public:
	Sidebar();
	~Sidebar() {}

	void draw(RenderWindow& window);

private:
	Vertex shader[4];
	RectangleShape sidebar;
};

#endif
