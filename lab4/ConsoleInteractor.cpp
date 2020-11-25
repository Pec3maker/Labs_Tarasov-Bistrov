#include "ConsoleInteractor.h"

void ConsoleInteractor::Help() const
{
	cout << "\"1\" - Create new Flat\n\"2\" - Delete Flat\n\"3\" - Help\n\"4\" - Print all flats\n\"5\" - Find flat by id\n\
\"6\" - Find flats by space\n\"7\" - Save register\n\"8\" - Exit\n";
}

void ConsoleInteractor::CreateFlat() 
{
	int space, countRooms, floor;
	string district;

	cout << "Enter space of new flat:\n";
	cout << ">> ";
	cin >> space;

	cout << "Enter count rooms of new flat:\n";
	cout << ">> ";
	cin >> countRooms;

	cout << "Enter floor of new flat:\n";
	cout << ">> ";
	cin >> floor;

	cout << "Enter district of new flat:\n";
	cout << ">> ";
	cin >> district;

	_flatRegister.AddFlat(space, countRooms, floor, district);
}

void ConsoleInteractor::DeleteFlat()
{
	int id;
	cout << "Enter id:\n";
	cout << ">> ";
	cin >> id;

	try
	{
		_flatRegister.DeleteFlat(id);
	}
	catch (const std::logic_error& err)
	{
		cout << err.what() << "\n";
	}
}

void ConsoleInteractor::PrintAllFlats() const
{
	cout << _flatRegister.ToString(0);
}

void ConsoleInteractor::SaveProgress() const
{
	ofstream out(_filename);
	out << _flatRegister.ToString(1);
	out.close();
}

void ConsoleInteractor::PrintFlatById() const
{
	int id;
	cout << "Enter id:\n";
	cout << ">> ";
	cin >> id;

	try
	{
		cout << _flatRegister.SearchFlatById(id) << "\n";
	}
	catch (const std::logic_error& err)
	{
		cout << err.what() << "\n";
	}
}

void ConsoleInteractor::PrintFlatsBySpace() const
{
	int space;
	cout << "Enter space to print you suitable houses:\n";
	cout << ">> ";
	cin >> space;

	std::vector<Flat*> findResult = _flatRegister.SearchFlatsBySpace(space);
	for (auto it : findResult)
	{
		cout << *it << "\n";
	}

}

void ConsoleInteractor::Init()
{
	int space, countRooms, floor;
	string district;
	ifstream in(_filename);

	if (!in)
	{
		cout << "register.txt is not exist or empty\n";
	}
	else
	{
		while (in)
		{
			in >> district >>  floor >> countRooms >> space;
			_flatRegister.AddFlat(space, countRooms, floor, district);
		}
	}
	in.close();


	bool flag = true;
	int code;

	while (flag)
	{
		
		cout << "Enter \"3\" - Help\n";
		cout << ">> ";


		cin >> code;

		switch (code)
		{
		case 1:
			CreateFlat();
			break;
		case 2:
			DeleteFlat();
			break;
		case 3:
			Help();
			break;
		case 4:
			PrintAllFlats();
			break;
		case 5:
			PrintFlatById();
			break;
		case 6:
			PrintFlatsBySpace();
			break;
		case 7:
			SaveProgress();
			break;
		case 8:
			flag = false;
			break;
		}
	}
}