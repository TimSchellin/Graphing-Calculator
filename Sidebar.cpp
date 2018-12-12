#include "Sidebar.h"

/*
	THINGS IM GONNA NEED:
	----------------------------
	- input field for equation to be typed
	- additional input fields that appear after newones
	- Queue of inputField objects???
	- Draw new field function?
	- Header on top of Bar, instructions, options
	- Text
	- Background color?
*/


Sidebar::Sidebar(){

	sidebar.setPosition(BAR_POS);
	sidebar.setSize(Vector2f(BAR_WIDTH, WINDOW_HEIGHT-BANNER_HEIGHT));
	sidebar.setFillColor(SIDEBAR_COLOR);

	shader[0] = Vertex(Vector2f(BAR_WIDTH + 5, BAR_POS.y), Color::Transparent);
	shader[1] = Vertex(Vector2f(BAR_WIDTH + 5, WINDOW_HEIGHT), Color::Transparent);
	shader[2] = Vertex(Vector2f(BAR_WIDTH, WINDOW_HEIGHT), Color(0, 0, 0, 180));
	shader[3] = Vertex(Vector2f(BAR_WIDTH, BAR_POS.y), Color(0,0,0, 180));
}

void Sidebar::draw(RenderWindow& window) {
	window.draw(sidebar);
	window.draw(shader, 4, Quads);
}
