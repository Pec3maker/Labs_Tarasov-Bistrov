#include "Rectangle.h"
#include "Trapezoid.h"

class Factory
{
public:
    virtual Shape* createShape(Point* cords) = 0;
    virtual ~Factory() {}
};

class RectangleFactory : public Factory
{
public:
    Shape* createShape(Point* cords) override
    {
        return new Rectangle(cords);
    }
};

class TrapezoidFactory : public Factory
{
public:
    Shape* createShape(Point* cords) override
    {
        return new Trapezoid(cords);
    }
};