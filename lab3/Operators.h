#include "Shape.h"

class Operators
{
public:
	int Compare(Shape* shape1, Shape* shape2) const;
	bool IsIntersect(Shape* shape1, Shape* shape2) const;
	bool IsInclude(Shape* shape1, Shape* shape2) const;

	double GetLength(Point& point1, Point& point2) const;
	double GetMaxRadius(Shape* shape) const;
};