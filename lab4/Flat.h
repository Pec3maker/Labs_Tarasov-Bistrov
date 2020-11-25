#pragma once
#include <string>
#include <iostream>

using std::string;

class Flat
{
public:

	Flat(int space, int countRooms, int floor, string district) : \
		_space(space), _countRooms(countRooms), _floor(floor), _district(district) {}


	int GetSpace() const;
	int GetCountRooms() const;
	int GetFloor() const;
	int GetId() const;
	const string& GetDistrict() const;

	friend std::ostream& operator<<(std::ostream& out, const Flat& flat);
	friend bool operator<(const Flat& a, const Flat& b);

private:
	const int _id = GenerateId();
	int _space;
	int _countRooms;
	int _floor;
	string _district;

	static int GenerateId();
};