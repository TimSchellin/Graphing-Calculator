#include "Token.h"
#include "StringToQueue.h"
#include "ShuntingYard.h"
#include "Interface.h"

#include <iostream>
#include <cmath>
#include <cassert>
#include <SFML/Graphics.hpp>

void pause();
void simpleSFML();

using namespace std;
using namespace sf;

void testRPN();

int main()
{
	//simpleSFML();

	//testRPN();
	Interface gui;
	gui.run();
	pause();
}

void pause() {
	int i;
	cin >> i;
}

void simpleSFML() {
	RenderWindow window(VideoMode(200, 200), "SFML works!");

	while (window.isOpen())
	{
		/*
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		*/
		window.clear();
		//window.draw(shape);
		window.display();
	}
	pause();
}

void testRPN() {
	String testString = "3*8+2";
	Queue<Token*> infixExpression = convert(testString);

	/*
	while (!infixExpression.empty()) {
		Token* p = infixExpression.pop();
		cout << " ";
		p->print();
	}
	*/

	Queue<Token*> postfixExpression = shuntingYard(infixExpression);

	while (!postfixExpression.empty()) {
		Token* p = postfixExpression.pop();
		cout << " ";
		p->print();
	}
}