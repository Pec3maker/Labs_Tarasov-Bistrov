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

	cout << "Enter points:\n";
	for (int i = 0; i < COUNT_POINTS; i++)
	{
		cout << "\n" << i + 1 << ") x: \n>> ";
		cin >> points[i].x;
		cout << "\n" << i + 1 << ") y: \n>> ";
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

		try
		{
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
		catch (const std::logic_error& src)
		{
			cout << src.what() << "\n";
		}
	}
	else
	{
		cout << "You don't have enought space, delete something\n";
	}
	delete[] points;
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

void ConsoleInteractor::Compare() const
{
	Operators operators;
	string name, name2;
	cout << "Enter name of first shape\n>> ";
	cin >> name;
	cout << "Enter name of second shape\n>> ";
	cin >> name2;
	int indexName1 = GetIndex(name);
	int indexName2 = GetIndex(name2);
	if (indexName1 != -1 && indexName2 != -1)
	{
		switch (operators.Compare(_cases[indexName1], _cases[indexName2]))
		{
		case 1:
			cout << "First shape larger than second\n";
			break;
		case -1:
			cout << "Second shape larger than first\n";
			break;
		case 0:
			cout << "Shapes have the same area\n";
			break;
		}
	}
	else
	{
		cout << "Wrong name\n";
	}
}

void ConsoleInteractor::Move() const
{
	string name;
	char side;
	double count;
	cout << "Enter name of shape\n>> ";
	cin >> name;
	int indexName1 = GetIndex(name);
	if (indexName1 != -1)
	{
		cout << "Which side?(u-up, l-left, r-right, d-down)\n>> ";
		cin >> side;
		cout << "How much\n>> ";
		cin >> count;
		_cases[indexName1]->Move(side, count);
	}
	else
	{
		cout << "Wrong name\n";
	}
}

void ConsoleInteractor::Rotate() const
{
	string name;
	int angle;
	cout << "Enter name of shape\n>> ";
	cin >> name;
	int indexName1 = GetIndex(name);
	if (indexName1 != -1)
	{
		cout << "Enter angle\n>> ";
		cin >> angle;
		_cases[indexName1]->Rotate(angle);
	}
	else
	{
		cout << "Wrong name\n";
	}
}

void ConsoleInteractor::GetArea() const
{
	string name;
	cout << "Enter name of shape\n>> ";
	cin >> name;
	int indexName1 = GetIndex(name);
	if (indexName1 != -1)
	{
		cout << "Area of this shape is " << _cases[indexName1]->GetArea() << "\n";
	}
	else
	{
		cout << "Wrong name\n";
	}
}

void ConsoleInteractor::GetCenter() const
{
	string name;
	cout << "Enter name of shape\n>> ";
	cin >> name;
	int indexName1 = GetIndex(name);
	if (indexName1 != -1)
	{
		Point center = _cases[indexName1]->GetCenter();
		cout << "Center of this shape: x = " << center.x << " y = " << center.y << "\n";
	}
	else
	{
		cout << "Wrong name\n";
	}
}

void ConsoleInteractor::IsIntersect() const
{
	Operators operators;
	string name, name2;
	cout << "Enter name of first shape\n>> ";
	cin >> name;
	cout << "Enter name of second shape\n>> ";
	cin >> name2;
	int indexName1 = GetIndex(name);
	int indexName2 = GetIndex(name2);
	if (indexName1 != -1 && indexName2 != -1)
	{
		if (operators.IsIntersect(_cases[indexName1], _cases[indexName2]))
		{
			cout << "Shapes intersect\n";
		}
		else
		{
			cout << "Shapes don't intersect\n";
		}
	}
	else
	{
		cout << "Wrong name\n";
	}
}

void ConsoleInteractor::Init() const
{
	bool flag = true;
	while (flag)
	{
		int code;
		cout << "Enter \"3\" - Help\n";
		cout << ">> ";
		cin >> code;

		switch (code)
		{
		case 1:
			CreateShape();
			break;
		case 2:
			DelShape();
			break;
		case 3:
			Help();
			break;
		case 4:
			Compare();
			break;
		case 5:
			IsIntersect();
			break;
		case 6:
			PrintShape();
			break;
		case 7:
			Move();
			break;
		case 8:
			Rotate();
			break;
		case 9:
			GetArea();
			break;
		case 10:

			break;
		case 11:
			flag = false;
			break;
		}
	}
}