#include "Operators.h"

int Operators::Compare(Shape& shape1, Shape& shape2) const
{
	int res;
	double area1 = shape1.GetArea();
	double area2 = shape2.GetArea();

	if (area1 > area2)
	{
		return 1;
	}
	else if (area1 < area2)
	{
		return -1;
	}
	return 0;
}

bool Operators::IsIntersect(Shape& shape1, Shape& shape2) const
{
	double radius1 = GetMaxRadius(shape1);
	double radius2 = GetMaxRadius(shape2);

	Point center1 = shape1.GetCenter();
	Point center2 = shape2.GetCenter();
	double length = GetLength(center1, center2);

	if (length > radius1 + radius2 || length <= abs(radius1 - radius2))
	{
		return false;
	}
	return true;
}

bool Operators::IsInclude(Shape& shape1, Shape& shape2) const
{
	double radius1 = GetMaxRadius(shape1);
	double radius2 = GetMaxRadius(shape2);

	Point center1 = shape1.GetCenter();
	Point center2 = shape2.GetCenter();
	double length = GetLength(center1, center2);

	if (length <= abs(radius1 - radius2))
	{
		return true;
	}
	return false;
}

double Operators::GetLength(Point& point1, Point& point2) const
{
	return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
}

double Operators::GetMaxRadius(Shape& shape) const
{
	double max = 0;
	Point center = shape.GetCenter();
	for (int i = 0; i < shape.GetCountCords(); i++)
	{
		double lenght = GetLength(center, shape.GetPoint(i));
		if (max < lenght)
		{
			max = lenght;
		}
	}

	return max;
}
