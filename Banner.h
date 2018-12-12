#ifndef BANNER_H
#define BANNER_H

#include <SFML/Graphics.hpp>
#include "Dimensions.h"

using namespace sf;

class Banner
{
public:
	Banner();
	~Banner() {}

	void draw(RenderWindow& window);
	
private:
	Text text;
	Font arial;
	RectangleShape banner;
};

#endif