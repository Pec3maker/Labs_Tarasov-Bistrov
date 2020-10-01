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
	cout << "Enter space for Pairs\n>> ";
	cin >> _count;
	_names = new string[_count];
	_cases = new Pair*[_count];
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

void ConsoleInteractor::Minus() const
{
	string name, name2;
	cout << "Enter name of first pair\n>> ";
	cin >> name;
	cout << "Enter name of second pair\n>> ";
	cin >> name2;
	int indexName1 = GetIndex(name);
	int indexName2 = GetIndex(name2);
	if (indexName1 != -1 && indexName2 != -1)
	{
		cout << _cases[indexName1]->GetPair() << "\n-\n";
		cout << _cases[indexName2]->GetPair() << "\n";
		cout << (_cases[indexName1]->Minus(*_cases[indexName2]))->GetPair() << "\n";
	}
	else
	{
		cout << "Wrond name\n";
	}
}

void ConsoleInteractor::Plus() const
{
	string name, name2;
	cout << "Enter name of first pair\n>> ";
	cin >> name;
	cout << "Enter name of second pair\n>> ";
	cin >> name2;
	int indexName1 = GetIndex(name);
	int indexName2 = GetIndex(name2);
	if (indexName1 != -1 && indexName2 != -1)
	{
		cout << _cases[indexName1]->GetPair() << "\n+\n";
		cout << _cases[indexName2]->GetPair() << "\n";
		cout << (_cases[indexName1]->Plus(*_cases[indexName2]))->GetPair() << "\n";
	}
	else
	{
		cout << "Wrond name\n";
	}
}

void ConsoleInteractor::Help() const
{
	cout << "\"1\" - Create new pair\n\"2\" - Delete pair\n\"3\" - Help\n\"4\" - Plus\n\"5\" - Minus\n\
\"6\" - Print pair\n\"7\" - Exit\n";
}

void ConsoleInteractor::CreatePair() const
{
	int firstNum, secondNum;
	cout << "Enter first num:\n>> ";
	cin >> firstNum;

	cout << "Enter second num:\n>> ";
	cin >> secondNum;

	cout << "Enter name of Pair:\n>> ";
	string name;
	cin >> name;

	int type;
	cout << "Is it Complex or Money (1 or 2):\n>> ";
	cin >> type;

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
		Pair* newElement = nullptr;
		if (type == 1)
		{
			newElement = new Complex(firstNum, secondNum);
		}
		else if (type == 2)
		{
			try
			{
				newElement = new Money(firstNum, secondNum);
			}
			catch (const std::logic_error& err)
			{
				cout << err.what();
				return;
			}
		}

		_names[index] = name;
		_cases[index] = newElement;
	}
	else
	{
		cout << "You don't have enought space, delete something\n";
	}
}

void ConsoleInteractor::DeletePair(const string& name) const
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

void ConsoleInteractor::PrintPair() const
{
	string name;
	cout << "Enter name of pair to print\n>> ";
	cin >> name;
	int index = GetIndex(name);
	if (index != -1)
	{
		cout << _cases[index]->GetPair() << "\n";
	}
	else
	{
		cout << "Wrong name\n";
	}
}

void ConsoleInteractor::DelPair() const
{
	string name;
	cout << "Enter name of pair to delete\n>> ";
	cin >> name;
	DeletePair(name);
	cout << "Complete\n";
}

void ConsoleInteractor::Init() const
{
	int code, arg; string name, name2;
	while (true)
	{
		cout << "Enter \"3\" - Help\n";
		cout << ">> ";
		cin >> code;

		if (code == 1)
		{
			CreatePair();
		}
		else if (code == 2)
		{
			DelPair();
		}
		else if (code == 3)
		{
			Help();
		}
		else if (code == 4)
		{
			Plus();
		}
		else if (code == 5)
		{
			Minus();
		}
		else if (code == 6)
		{
			PrintPair();
		}
		else if (code == 7)
		{
			break;
		}
	}
}
