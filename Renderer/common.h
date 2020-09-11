#ifndef __COMMON__
#define __COMMON__

#include <SFML/Graphics.hpp>
#include <limits.h>

#include <math.h>
#include <corecrt_math_defines.h>

#include "graphics.h"

#define MEASURE 640
#define MAX_RGBA 255

#define SPEED 0.03
#define TURN 0.1
#define INIT_POS { 118.9, 247.31 }

#define RAD(x) ((x) * M_PI/180)
#define CHECK(key) if(sf::Keyboard::isKeyPressed(sf::Keyboard::##key))
//^^^An evil macro

void DrawRects(sf::RenderWindow& rWind, sf::RectangleShape* rects, size_t sz);
sf::RectangleShape* ConstructFOV(int angle, double angleOff, double length,
	Graphics::Point pos, Graphics::Line* map, size_t map_len);

#endif
