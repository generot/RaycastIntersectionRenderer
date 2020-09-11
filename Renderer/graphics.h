#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

namespace Graphics {
	struct Point {
		//Coordinates
		double x, y;

		double DistSq(Point& other);
		double Dist(Point& other);
	};

	struct IntersectionData : Point {
		double t, u;
		IntersectionData(const Point& pnt, double _t, double _u);
	};

	class Line {
	private:
		Point p1, p2;

	public:
		//From two points;
		Line(const Point& _p1, const Point& _p2);

		//From angle
		Line(Point offset, double angle, double length);

		IntersectionData Intersects(const Line& ln);
	};
}

#endif
