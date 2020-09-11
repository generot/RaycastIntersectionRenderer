#include "common.h"

using namespace Graphics;

double Point::DistSq(Point& other) {
	Point distP = { x - other.x, y - other.y };
	return distP.x * distP.x + distP.y * distP.y;
}

double Point::Dist(Point& other) {
	return sqrt(DistSq(other));
}

IntersectionData::IntersectionData(const Point& pnt, double _t, double _u) : Point(pnt), t(_t), u(_u) {}

Line::Line(const Point& _p1, const Point& _p2) : p1(_p1), p2(_p2) {}

Line::Line(Point offset, double angle, double length) {
	Point origin(offset);
	Point end = { cos(RAD(angle)) * length, sin(RAD(angle)) * length };

	p1 = end;
	p2 = origin;
}

IntersectionData Line::Intersects(const Line& ln) {
	double t, u, div;
	div = (p1.x - p2.x) * (ln.p1.y - ln.p2.y) - (p1.y - p2.y) * (ln.p1.x - ln.p2.x);

	t = ((p1.x - ln.p1.x) * (ln.p1.y - ln.p2.y) - (p1.y - ln.p1.y) * (ln.p1.x - ln.p2.x)) / div;
	u = ((p1.x - p2.x) * (p1.y - ln.p1.y) - (p1.y - p2.y) * (ln.p1.x - ln.p2.x)) / div;

	Point pOfIntr = { p1.x + t * (p2.x - p1.x), p1.y + t * (p2.y - p1.y) };
	return IntersectionData(pOfIntr, t, u);
}