#ifndef COORDINATES_H
#define COORDINATES_H

struct Coordinates {

	Coordinates() : x(0), y(0) {}

	Coordinates(int i, int j) : x(i), y(j) {}

	Coordinates& operator=(Coordinates other) {
		if (&other == this)
			return *this;

		x = other.x;
		y = other.y;
		return *this;
	}

	int x;
	int y;
};

#endif