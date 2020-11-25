#pragma once
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "Flat.h"

struct Compare
{
	bool operator()(const Flat* a,const Flat* b) const 
	{
		return a->GetSpace() < b->GetSpace();
	}
};

class Register
{
public:

	Register() = default;
	~Register();

	void AddFlat(int space, int countRooms, int floor, const string& district);
	void DeleteFlat(int id);
	const Flat& SearchFlatById(int id) const;
	const std::vector<Flat*> SearchFlatsBySpace(int space) const;
	string ToString(int code) const;

private:
	std::map<int, Flat*> _flatId;
	std::set<Flat*, Compare> _flatSpace;

	void CheckId(int id) const;
};

