#include "Interface.h"
#include "sfVectorConversion.h"

Interface::Interface() : sidebar(){
	window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Graphing Calculator");
	window.setFramerateLimit(60);

	window.setPosition(Vector2i(50, 20));
	inputFields.push_back(new InputField(getCellPosition(), "f1"));
	inputFields.push_back(new InputField(getCellPosition(), "f2"));
	inputFields.push_back(new InputField(getCellPosition(), "f3"));
}

void Interface::run() {
	while (window.isOpen()) {
		checkEvents();
		render();
	}
}
void Interface::checkEvents() {
	Event event;
	while (window.pollEvent(event)) {
		if(event.type == Event::Closed) {
			window.close();
			break;
		}
		if (event.type == Event::MouseButtonPressed) 
		{
			if (event.mouseButton.button == Mouse::Left)
			{
				for (int i = 0; i < inputFields.size(); i++)
				{
					inputFields[i]->clearCell();
					if (inputFields[i]->isInside(toFloat(Mouse::getPosition(window))))
					{
						inputFields[i]->onClick();
					}
				}
			}
		}
	}	
}

void Interface::render() {
	window.clear(Color(255, 255, 255, 128));
	draw();
	window.display();
}

void Interface::draw() {

	graphPlane.draw(window);
	//drawFunctions();
	sidebar.draw(window);
	banner.draw(window);
	drawFields();
}

void Interface::drawFunctions() {
	for (int i = 0; i < userFunctions.size(); i++) {
		userFunctions[i]->draw(window);
	}
}

void Interface::drawFields() {
	for (int i = 0; i < inputFields.size(); i++) {
		inputFields[i]->draw(window);
	}
}

void Interface::addFunction(String functionStr) {
	inputFields.push_back(new InputField(getCellPosition(), functionStr));
	userFunctions.push_back(new UserFunction(/* waiting to define args*/));
}

Vector2f Interface::getCellPosition() {
	return (Vector2f(0, BANNER_HEIGHT + inputFields.size()*CELL_HEIGHT));
}

