#ifndef INTERFACE_H
#define INTERFACE_H

#include "Dimensions.h"
#include "UserFunction.h"
#include "InputField.h"
#include "Banner.h"
#include "Sidebar.h"
#include "GraphPlane.h"
#include "Queue.h"


#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Interface
{
public:
	Interface();
	~Interface() {}

	void run();
	void checkEvents();
	void render();
	void draw();
	void drawFunctions();
	void drawFields();
	void addFunction(String functionString);

	Vector2f getCellPosition();

private:
	Banner banner;
	RenderWindow window;
	Sidebar sidebar;
	GraphPlane graphPlane;

	vector<InputField*> inputFields;
	vector<UserFunction*> userFunctions;

	bool mouseClicked = false;
	bool mouseInsideRect = false;
	bool dragging = false;

	Vector2f mouseRectOffset;

	int mouseX = 0;
	int mouseY = 0;
};

#endif