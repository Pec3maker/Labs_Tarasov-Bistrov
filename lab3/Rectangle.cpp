#include "Rectangle.h"

using std::logic_error;

Rectangle::Rectangle(Point* cords)
{
	_countCords = 4;
	
	if (!RightShape(cords))
	{
		throw logic_error("WRONG_SHAPE");
	}

	_cords = new Point[_countCords];
	_lenghtSides = new double[_countCords];
	memcpy(_cords, cords, sizeof(Point) * _countCords);

	CalculateSides();
}

double Rectangle::GetArea() const
{
	return _lenghtSides[0] * _lenghtSides[1];
}

Point Rectangle::GetCenter() const
{
	Point center;
	center.y = (_cords[0].y + _cords[1].y + _cords[2].y + _cords[3].y) / _countCords;
	center.x = (_cords[0].x + _cords[1].x + _cords[2].x + _cords[3].x) / _countCords;
	return center;
}

bool Rectangle::RightShape(Point* cords) const
{
	double diagonal1 = sqrt(pow(cords[0].x - cords[2].x, 2) + pow(cords[0].y - cords[2].y, 2));
	double diagonal2 = sqrt(pow(cords[1].x - cords[3].x, 2) + pow(cords[1].y - cords[3].y, 2));
	if (diagonal1 == diagonal2)
	{
		return true;
	}
	return false;
}