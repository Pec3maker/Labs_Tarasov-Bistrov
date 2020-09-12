//interface.cpp
#define COUNT_OF_CASES 10
#include <iostream>
#include "interface.h"

Interface::~Interface()
{
	delete[] _names;
	delete[] _cases;
}

Interface::Interface()
{
	_names = new std::string[COUNT_OF_CASES];
	_cases = new Polinom[COUNT_OF_CASES];
}

int Interface::GetIndex(std::string name) const
{
	for (int i = 0; i < COUNT_OF_CASES; i++)
	{
		if (name == _names[i])
		{
			return i;
		}
	}
	return -1;
}

void Interface::Minus() const
{
	std::string name, name2;
	std::cout << "Enter name of first polinom\n>> ";
	std::cin >> name;
	std::cout << "Enter name of second polinom\n>> ";
	std::cin >> name2;
	if (GetIndex(name) != -1 && GetIndex(name2) != -1)
	{
		std::cout << _cases[GetIndex(name)] << "\n-\n";
		std::cout << _cases[GetIndex(name2)] << "\n";
		std::cout << _cases[GetIndex(name)] - _cases[GetIndex(name2)] << "\n";
	}
	else
	{
		std::cout << "Wrond name\n";
	}
}

void Interface::Plus() const
{
	std::string name, name2;
	std::cout << "Enter name of first polinom\n>> ";
	std::cin >> name;
	std::cout << "Enter name of second polinom\n>> ";
	std::cin >> name2;
	if (GetIndex(name) != -1 && GetIndex(name2) != -1)
	{
		std::cout << _cases[GetIndex(name)] << "\n+\n";
		std::cout << _cases[GetIndex(name2)] << "\n";
		std::cout << _cases[GetIndex(name)] + _cases[GetIndex(name2)] << "\n";
	}
	else
	{
		std::cout << "Wrond name\n";
	}
}

void Interface::EditPoli(std::string name) const
{
	int degree; double* multipliers;
	std::cout << "Enter name of polinom to edit\n>> ";
	std::cin >> name;
	if (GetIndex(name) != -1)
	{

		std::cout << "Enter new dergee\n>> ";
		std::cin >> degree;

		std::cout << "Enter " << degree + 1 << " new multipliers separated by a space\n>> ";
		multipliers = new double[degree + 1];
		for (int i = 0; i < degree + 1; i++)
		{
			std::cin >> multipliers[i];
		}

		_cases[GetIndex(name)].SetPoli(degree, multipliers);
		delete[] multipliers;
	}
	else
	{
		std::cout << "Wrong name\n";
	}
}

void Interface::Help() const
{
	std::cout << "\"1\" - Create new polinom\n\"2\"- Delete polinom\n\"3\"- Help\n\"4\" - Set Polinom\n\"5\" - Plus\n\
\"6\" - Minus\n\"7\" - Sign inversion\n\"8\" - Solve polinom\n\"9\" - Get Degree\n\"10\"- Get multiplier\n\"11\" - Print polinom\n\"12\" - Exit\n";
}

void Interface::CreatePoli() const
{
	int degree; double* multipliers; std::string name; bool isEnoughtSpace = false; int index;
	std::cout << "Enter degree:\n>> ";
	std::cin >> degree;

	multipliers = new double[degree + 1];

	std::cout << "Enter " << degree + 1 << " multipliers separated by a space\n>> ";
	for (int i = 0; i < degree + 1; i++)
	{
		std::cin >> multipliers[i];
	}

	std::cout << "Enter name of polinom\n>> ";
	std::cin >> name;

	for (int i = 0; i < COUNT_OF_CASES; i++)
	{
		if (_names[i].empty())
		{
			isEnoughtSpace = true;
			index = i;
		}
	}

	if (isEnoughtSpace)
	{
		Polinom temp(degree, multipliers);
		_names[index] = name;
		_cases[index] = temp;
	}
	else
	{
		std::cout << "You don't have enought space, delete something\n";
	}

	delete[] multipliers;
}

void Interface::DeletePoli(std::string name) const
{
	int index = GetIndex(name);

	if (index == -1)
	{
		std::cout << "Can't find polinom with this name\n";
	}
	else
	{
		_names[index] = "";
	}
}

void Interface::Init() const
{
	int code, arg; std::string name, name2;
	while (true)
	{
		std::cout << "Enter \"3\" - Help\n";
		std::cout << ">> ";
		std::cin >> code;

		if (code == 1)
		{
			CreatePoli();
		}
		else if (code == 2)
		{
			std::cout << "Enter name of polinom to delete\n>> ";
			std::cin >> name;
			DeletePoli(name);
			std::cout << "Complete\n";
		}
		else if (code == 3)
		{
			Help();
		}
		else if (code == 4)
		{
			EditPoli(name);
			std::cout << "Complete\n";
		}
		else if (code == 5)
		{
			Plus();
		}
		else if (code == 6)
		{
			Minus();
		}
		else if (code == 7)
		{
			std::cout << "Enter name of polinom to invert\n>> ";
			std::cin >> name;
			if (GetIndex(name) != -1)
			{
				std::cout << "-(" << _cases[GetIndex(name)] << ")" << "\n = \n" << -_cases[GetIndex(name)] << "\n";
			}
			else
			{
				std::cout << "Wrong name\n";
			}
		}
		else if (code == 8)
		{
			std::cout << "Enter name of polinom to solve\n>> ";
			std::cin >> name;
			if (GetIndex(name) != -1)
			{
				std::cout << "Enter arg of polinom\n>> ";
				std::cin >> arg;
				std::cout << "f(x) = " << _cases[GetIndex(name)] << "\n" << "f(" << arg << ") = " << _cases[GetIndex(name)].SolvePoli(arg) << "\n";
			}
			else
			{
				std::cout << "Wrong name\n";
			}
		}
		else if (code == 9)
		{
			std::cout << "Enter name of polinom to get degree\n>> ";
			std::cin >> name;
			std::cout << "Degree = " << _cases[GetIndex(name)].GetDegree() << "\n";
		}
		else if (code == 10)
		{
			std::cout << "Enter name of polinom to get multiplier\n>> ";
			std::cin >> name;
			std::cout << "Enter index of multipliers to get multiplier\n>> ";
			std::cin >> arg;
			if (_cases[GetIndex(name)].GetDegree() < arg)
			{
				std::cout << "Wrong degree\n";
			}
			else
			{
				std::cout << "Multiplier[i] = " << _cases[GetIndex(name)][arg] << "\n";
			}
		}
		else if (code == 11)
		{
			std::cout << "Enter name of polinom to print\n>> ";
			std::cin >> name;
			if (GetIndex(name) != -1)
			{
				std::cout << _cases[GetIndex(name)] << "\n";
			}
			else
			{
				std::cout << "Wrong name\n";
			}
		}
		else if(code == 12)
		{
			break;
		}
	}
}
