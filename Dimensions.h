#ifndef DIMENSIONS_H
#define DIMENSIONS_H

#include <SFML/Graphics.hpp>
// THIS HEADER FILE IS FOR STORING
// DIMENSION CONSTANTS

using namespace sf;

//GLOBALS
//float SCALE = 1;
//Vector2f OFFSET;

extern Vector2f OFFSET;
extern float SCALE;
extern float YSCALE;
// main window
const int WINDOW_HEIGHT = 600;
const int WINDOW_WIDTH = 1050;

// banner
const int BANNER_HEIGHT = 45;
const Vector2f BANNER_POS(0, 0);

// sidebar
const int BAR_WIDTH = 300;
const int CELL_HEIGHT = 65;
const Vector2f BAR_POS(0, BANNER_HEIGHT);

const int GRID_RATIO = 80;

// graph plane
const int GRAPH_WIDTH = WINDOW_WIDTH - BAR_WIDTH;
const int GRAPH_HEIGHT = WINDOW_HEIGHT - BANNER_HEIGHT;
const int MID_WIDTH = GRAPH_WIDTH / 2;
const int MID_HEIGHT = GRAPH_HEIGHT / 2;
const Vector2f GRAPH_POS(BAR_WIDTH, BANNER_HEIGHT);
const Vector2f ORIGIN(BAR_WIDTH + (GRAPH_WIDTH/2), BANNER_HEIGHT + (GRAPH_HEIGHT/2));

const int X_MIN = BAR_WIDTH;
const int X_MAX = WINDOW_WIDTH;

const int Y_MIN = BANNER_HEIGHT;
const int Y_MAX = WINDOW_HEIGHT;

//colors
const Color SIDEBAR_COLOR =	Color(235, 235, 235);
const Color GRAPH_COLOR   =	Color(40, 40, 40);
const Color AXIS_COLOR    =	Color(240, 240, 240, 200);
const Color GRID_COLOR    = Color(90, 90, 90);
const Color M_GRID_COLOR  = Color(90, 90, 90, 50);  // semi-transparent alpha channel
const Color BANNER_COLOR  =	Color(0, 128, 128);
const Color INPUT_COLOR   = Color(235, 235, 235);
const Color HIGHLIGHT1    = Color(255, 255, 255);
const Color HIGHLIGHT2 = Color(0, 100, 140, 128);
const Color TRANSPARENT = Color(0, 0, 0, 0);

const Color CURVE_COLOR = Color(255, 0, 0);
//fonts

# endif