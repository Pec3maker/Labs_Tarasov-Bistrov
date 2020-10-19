#include "Shape.h"

class Trapezoid : public Shape
{
public:
	Trapezoid(Point* cords);

	double GetArea() const override;
	Point GetCenter() const override;
private:
	bool RightShape(Point* cords) const;
	bool IsParallelSides(const Point& a1, const Point& a2, const Point& b1, const Point& b2) const;
	double GetH() const;
	double GetAreaTriangle(const Point& dot1, const Point& dot2, const Point& dot3) const;
};