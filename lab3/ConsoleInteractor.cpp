#include <iostream>
#include "ConsoleInteractor.h"

using std::cin;
using std::cout;

ConsoleInteractor::~ConsoleInteractor()
{
	for (int i = 0; i < _count; i++)
	{
		if (_names[i] != "")
		{
			delete _cases[i];
		}
	}
	delete[] _names;
	delete[] _cases;
}

ConsoleInteractor::ConsoleInteractor()
{
	cout << "Enter space for Shapes\n>> ";
	cin >> _count;
	_names = new string[_count];
	_cases = new Shape* [_count];
}

int ConsoleInteractor::GetIndex(const string& name) const
{
	for (int i = 0; i < _count; i++)
	{
		if (name == _names[i])
		{
			return i;
		}
	}
	return -1;
}

void ConsoleInteractor::Help() const
{
	cout << "\"1\" - Create new Shape\n\"2\" - Delete Shape\n\"3\" - Help\n\"4\" - Compare \n\"5\" - IsIntersect\n\
\"6\" - Print Shape\n\"7\" - Move\n\"8\" - Rotate\n\"9\" - Get Area\n\"10\" - Get Center\n\"11\" - Exit\n";
}

void ConsoleInteractor::CreateShape() const
{
	RectangleFactory rectangleFactory;
	TrapezoidFactory trapezoidFactory;

	cout << "Enter name of Shape:\n>> ";
	string name;
	cin >> name;

	int type;
	cout << "Is it Rectangle or Trapezoid (1 or 2):\n>> ";
	cin >> type;

	Point* points = new Point[COUNT_POINTS];

	cout << "Enter point(x y) separated by space:\n>> ";
	for (int i = 0; i < COUNT_POINTS; i++)
	{
		cout << i << "\n) x: \n>> ";
		cin >> points[i].x;
		cout << i << "\ny: \n>> ";
		cin >> points[i].y;
	}

	bool isEnoughtSpace = false;
	int index;
	for (int i = 0; i < _count && !isEnoughtSpace; i++)
	{
		if (_names[i].empty())
		{
			isEnoughtSpace = true;
			index = i;
		}
	}

	if (isEnoughtSpace)
	{
		Shape* newElement = nullptr;
		if (type == 1)
		{
			newElement = rectangleFactory.createShape(points);
		}
		else if (type == 2)
		{
			newElement = trapezoidFactory.createShape(points);
		}

		_names[index] = name;
		_cases[index] = newElement;
	}
	else
	{
		cout << "You don't have enought space, delete something\n";
	}
}

void ConsoleInteractor::DeleteShape(const string& name) const
{
	int index = GetIndex(name);

	if (index == -1)
	{
		cout << "Can't find pair with this name\n";
	}
	else
	{
		_names[index] = "";
		delete _cases[index];
		_cases[index] = nullptr;
	}
}

void ConsoleInteractor::PrintShape() const
{
	string name;
	cout << "Enter name of pair to print\n>> ";
	cin >> name;
	int index = GetIndex(name);
	if (index != -1)
	{
		cout << _cases[index]->ToString() << "\n";
	}
	else
	{
		cout << "Wrong name\n";
	}
}

void ConsoleInteractor::DelShape() const
{
	string name;
	cout << "Enter name of pair to delete\n>> ";
	cin >> name;
	DeleteShape(name);
	cout << "Complete\n";
}

//cout << "\"1\" - Create new Shape\n\"2\" - Delete Shape\n\"3\" - Help\n\"4\" - Compare \n\"5\" - IsIntersect\n\
//\"6\" - Print Shape\n\"7\" - Move\n\"8\" - Rotate\n\"9\" - Get Area\n\"10\" - Get Center\n\"11\" - Exit\n";

void ConsoleInteractor::Init() const
{
	Operators operators;
	while (true)
	{
		int code;
		cout << "Enter \"3\" - Help\n";
		cout << ">> ";
		cin >> code;

		if (code == 1)
		{
			CreateShape();
		}
		else if (code == 2)
		{
			DelShape();
		}
		else if (code == 3)
		{
			Help();
		}
		else if (code == 4)
		{
			
		}
		else if (code == 5)
		{
			Minus();
		}
		else if (code == 6)
		{
			PrintShape();
		}
		else if (code == 7)
		{
			break;
		}
	}
}