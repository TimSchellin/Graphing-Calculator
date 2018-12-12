#ifndef INPUTFIELD_H
#define INPUTFIELD_H

#include <SFML/Graphics.hpp>
#include "Dimensions.h"
//#include "Interface.h"

using namespace sf;

class InputField
{
public:
	InputField(Vector2f position, String text);
	~InputField() {}
	
	bool isInside(Vector2f position);
	void createOutline(Vector2f pos);
	void draw(RenderWindow& window);
	void onClick();
	void clearCell();
	//void setText(String inputText);

private:

	int lineW = 1;
	bool selected = false;

	Text FunctionStr;

	Font ariel;
	Font times;

	RectangleShape inputCell;
	RectangleShape outline;
	RectangleShape bullet;
};

#endif