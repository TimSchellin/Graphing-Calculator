#include "Token.h"
#include "Interface.h"

#include <iostream>
#include <cmath>
#include <cassert>
#include <SFML/Graphics.hpp>
#include <stdio.h>

#include "RPN.h"
#include "ShuntingYard.h"
#include "StringToQueue.h"
void pause();
void menu();

using namespace std;
using namespace sf;

extern vector<String> functions;

int main()
{
	menu();
	Interface gui;
	gui.run();
	pause();
}

void pause() {
	int i;
	cin >> i;
}

void menu() {
	int num = 0;
	cout << "how many functions would you like to input? > ";
	cin >> num;
	cout << "\n\n";
	for (int i = 0; i < num; i++) {
		std::string temp;
		cout << "enter function " << i+1 << " > ";
		cin >> temp;
		functions.push_back(static_cast<String>(temp));
	}
}