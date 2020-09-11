#include "common.h"

void DrawRects(sf::RenderWindow& rWind, sf::RectangleShape* rects, size_t sz) {
	for (size_t i = 0; i < sz; i++)
		rWind.draw(rects[i]);

	return;
}

//Free the allocated memory after usage
sf::RectangleShape *ConstructFOV(int angle, double angleOff, double length, Graphics::Point pos, Graphics::Line *map, size_t map_len) {
	sf::RectangleShape* rects = new sf::RectangleShape[angle];

	for (double i = -angle / 2; i < angle / 2; i++) {
		Graphics::Line ray(pos, i + angleOff, length);

		Graphics::Point closestPoint = { (double)MEASURE + 30, (double)MEASURE + 30 };

		for (size_t j = 0; j < map_len; j++) {
			Graphics::IntersectionData iData = ray.Intersects(map[j]);
			Graphics::Point intrsPoint = { iData.x, iData.y };

			if (intrsPoint.DistSq(pos) < closestPoint.DistSq(pos) && 
					iData.t >= 0.0 && iData.t <= 1.0 && iData.u >= 0.0 && iData.u <= 1.0)
				closestPoint = intrsPoint;
		}

		double rSq = 1 / pos.DistSq(closestPoint);

		double rectY = (double)MEASURE * (double)MEASURE * rSq;
		int index = i + angle / 2;

		rects[index] = sf::RectangleShape(sf::Vector2f(MEASURE / angle, -rectY));
		rects[index].move(sf::Vector2f(index * ((float)MEASURE / angle), ((float)MEASURE + rectY)/2));
		
		sf::Color col(MAX_RGBA, MAX_RGBA, MAX_RGBA, MAX_RGBA * MAX_RGBA * rSq);
		rects[index].setFillColor(col);
	}

	return rects;
}