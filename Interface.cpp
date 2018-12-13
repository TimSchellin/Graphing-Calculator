#include "Interface.h"
#include "sfVectorConversion.h"

Vector2f OFFSET = Vector2f(0,0);
float SCALE = 1;
float YSCALE;
bool dragging = false;

vector<String> functions;

Interface::Interface() : sidebar(){
	window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Graphing Calculator");
	window.setFramerateLimit(60);

	window.setPosition(Vector2i(50, 20));
	for (int i = 0; i < functions.size(); i++) {
		inputFields.push_back(new InputField(getCellPosition(), functions[i]));
		userFunctions.push_back(new UserFunction());
	};
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
		else if (event.type == Event::MouseButtonPressed) 
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
		else if (event.type == Event::MouseMoved) {
			if (dragging) {
				Vector2i mousePos = Mouse::getPosition();
				//mouseX += mousePos.x - mouseX;
				//mouseY += mousePos.y - mouseY;
				OFFSET.x += ((mousePos.x - ORIGIN.x) - mouseX)*0.1;
				OFFSET.y += ((mousePos.y - ORIGIN.y) - mouseY)*0.1;
			}
		}
		else if (event.type == sf::Event::MouseWheelMoved) {\
			SCALE += event.mouseWheel.delta*0.1;
		}
		if (event.type == Event::MouseButtonPressed) {
			dragging = true;
			mouseX = Mouse::getPosition().x - ORIGIN.x;
			mouseY = Mouse::getPosition().y - ORIGIN.y;

		}
		if (event.type == Event::MouseButtonReleased) {
			dragging = false;
		}
	}	
}

void Interface::render() {
	window.clear(Color(255, 255, 255, 128));
	YSCALE = pow(2.71828, SCALE);
	if (SCALE < -2.3) {
		SCALE = -2.3;
	}
	draw();
	window.display();
}

void Interface::draw() {

	graphPlane.draw(window);
	drawFunctions();
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

