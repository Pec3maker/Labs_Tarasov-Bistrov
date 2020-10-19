#pragma once
#include <stdexcept>  
#include <cmath>
#include <string>

struct Point
{
	double x;
	double y;


};

class Shape
{
public:
	Shape() : _cords(nullptr), _countCords(0), _lenghtSides(nullptr) {}
	virtual ~Shape();

	int GetCountCords() const;
	double GetSide(const int index) const;
	void Move(const char direction, const double count);
	std::string ToString() const;

	Point& GetPoint(const int index) const;

	void Rotate(const int angle);
	virtual double GetArea() const = 0;
	virtual Point GetCenter() const = 0;
	

protected:
	Point* _cords;
	int _countCords;
	double* _lenghtSides;

	const double PI = 3.14159265358979323846;

	void CalculateSides();

	bool IsParallelSides(const Point& a1, const Point& a2, const Point& b1, const Point& b2) const;
};