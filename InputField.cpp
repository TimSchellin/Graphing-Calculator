#include "InputField.h"
#include <iostream>

InputField::InputField(Vector2f position, String text){
	inputCell.setPosition(position);
	inputCell.setSize(Vector2f(BAR_WIDTH, CELL_HEIGHT));
	inputCell.setFillColor(INPUT_COLOR);

	createOutline(position);

	/* TEXT STUFF */
	times.loadFromFile("times.ttf");
	Vector2f newPos(position.x + 20, position.y + (CELL_HEIGHT/2)-20);
	FunctionStr.setFont(times);
	FunctionStr.setString(text);
	FunctionStr.setPosition(newPos);
	FunctionStr.setCharacterSize(25);
	FunctionStr.setFillColor(Color::Black);
	FunctionStr.setStyle(Text::Regular);
}

void InputField::onClick() {

	selected = true;
	if (inputCell.getFillColor() == INPUT_COLOR) {
		inputCell.setFillColor(HIGHLIGHT1);
		outline.setOutlineColor(HIGHLIGHT2);
	}
	else clearCell();
}

void InputField::draw(RenderWindow& window) {
	window.draw(inputCell);
	window.draw(FunctionStr);
	window.draw(outline);
}

bool InputField::isInside(Vector2f position) {
	return inputCell.getGlobalBounds().contains(position);
}

void InputField::createOutline(Vector2f pos) {
	Vector2f newPos = Vector2f(pos.x + lineW, pos.y);
	outline.setPosition(newPos);
	outline.setSize(Vector2f(BAR_WIDTH-lineW*2, CELL_HEIGHT-lineW*2));
	outline.setOutlineThickness(static_cast<float>(lineW));
	clearCell();
}

void InputField::clearCell() {
	inputCell.setFillColor(INPUT_COLOR);
	//outline.setOutlineColor(TRANSPARENT);
	outline.setFillColor(Color(255, 255, 255, 10));// TRANSPARENT);
	outline.setOutlineColor(Color(0, 0, 0, 20));
}