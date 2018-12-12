#include "Banner.h"



Banner::Banner()
{
	banner.setPosition(BANNER_POS);
	banner.setSize(Vector2f(WINDOW_WIDTH, BANNER_HEIGHT));
	banner.setFillColor(BANNER_COLOR);

	arial.loadFromFile("arial.ttf");
	text.setFont(arial);
	text.setString("\t\t\t\tINPUT\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   GRAPH");
	text.setLetterSpacing(1.5);
	text.setPosition(Vector2f(0, BANNER_HEIGHT/2-9));
	text.setCharacterSize(18);
	text.setFillColor(Color(0,0,0,40));
	text.setStyle(Text::Bold);
}


void Banner::draw(RenderWindow& window) {
	window.draw(banner);
	window.draw(text);
}
