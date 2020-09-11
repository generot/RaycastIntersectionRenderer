#include <iostream>
#include "common.h"

int main() {
	using namespace Graphics;

	sf::RenderWindow wind(sf::VideoMode(MEASURE, MEASURE), "Raycasting");

	int angle = 80;
	double rayLen = 100.0, offst = 0.0;

	Point pos = INIT_POS;

	Line map[] = {
		Line(Point({0, 300}),	Point({100, 200})),
		Line(Point({100, 200}), Point({300, 400})),
		Line(Point({300, 400}), Point({400, 400})),
		Line(Point({400, 400}), Point({500, 200})),
		Line(Point({500, 200}), Point({600, 300})),
		Line(Point({300, 250}), Point({400, 250})),
		Line(Point({200, 150}), Point({300, 150}))
	};

	std::cout /*--------*/
	<< "W - Move forward\n"
	<< "A - Move left\n"
	<< "S - Move backwards\n"
	<< "D - Move right\n\n"
	<< "E - Turn left\n"
	<< "Space - Turn right\n";

	while (wind.isOpen()) {
		sf::Event event;

		while (wind.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				wind.close();
		}

		wind.clear();

		CHECK(W)		pos.y -= SPEED;
		CHECK(A)		pos.x -= SPEED;
		CHECK(S)		pos.y += SPEED;
		CHECK(D)		pos.x += SPEED;
		CHECK(Space)	offst += TURN;
		CHECK(E)		offst -= TURN;

		sf::RectangleShape* rects = ConstructFOV((double)angle, offst, 
				rayLen, pos, map, sizeof(map)/sizeof(Line));

		DrawRects(wind, rects, angle);
		wind.display();

		delete[] rects;
	}

	return 0;
}