#include "Token.h"
#include "StringToQueue.h"
#include "ShuntingYard.h"
#include <iostream>
#include <cmath>
#include <cassert>
#include <SFML/Graphics.hpp>

void pause();

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(200, 200), "SFML works!");
	CircleShape shape(100.f);
	shape.setFillColor(Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
	pause();
	return 0;
}

void pause() {
	int i;
	cin >> i;
}