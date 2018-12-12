#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

Vector2f toFloat(Vector2i other) {
	float _x = static_cast<float>(other.x);
	float _y = static_cast<float>(other.y);
	return Vector2f(_x, _y);
}