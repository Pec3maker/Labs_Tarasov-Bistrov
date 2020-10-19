#include "Shape.h"
#include <stdexcept>

class Rectangle : public Shape
{
public:
	Rectangle(Point* cords);

	double GetArea() const override;
	Point GetCenter() const override;
private:
	bool RightShape(Point* cords) const;
};