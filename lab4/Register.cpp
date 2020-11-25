#include "Register.h"

Register::~Register()
{
	if (_flatId.size())
	{
		for (auto it : _flatId)
		{
			delete it.second;
		}
	}

	_flatId.clear();
	_flatSpace.clear();
}

void Register::AddFlat(int space, int countRooms, int floor, const string& district)
{
	Flat* newFlat = new Flat(space, countRooms, floor, district);
	_flatId[newFlat->GetId()] = newFlat;
	_flatSpace.insert(newFlat);
}

void Register::DeleteFlat(int id)
{
	auto itId = _flatId.find(id);
	Flat* flat = itId->second;

	CheckId(id);

	_flatSpace.erase(flat);
	_flatId.erase(itId);
}

const Flat& Register::SearchFlatById(int id) const
{
	CheckId(id);
	return *(_flatId.find(id)->second);
}

const std::vector<Flat*> Register::SearchFlatsBySpace(int space) const
{
	std::vector<Flat*> res;

	Flat min(space - space / 10, 0, 0, ""), max(space + space / 10, 0, 0, "");
	for (auto it = _flatSpace.lower_bound(&min); it != _flatSpace.upper_bound(&max); ++it)
	{
		res.push_back(*it);
	}

	return res;
}

string Register::ToString(int code) const
{
	string out = "";

	if (code)
	{
		for (auto it : _flatSpace)
		{
			out +=it->GetDistrict() + " " + \
				std::to_string(it->GetFloor()) + " " + std::to_string(it->GetCountRooms()) + \
				" " + std::to_string(it->GetSpace()) + "\n";
		}
	}
	else
	{
		for (auto it : _flatSpace)
		{
			out += "Id: " + std::to_string(it->GetId()) + " | District: " + it->GetDistrict() + " | Floor: " + \
				std::to_string(it->GetFloor()) + " | Count rooms: " + std::to_string(it->GetCountRooms()) + \
				" | Space: " + std::to_string(it->GetSpace()) + "\n";
		}
	}

	return out;
}

void Register::CheckId(int id) const
{
	auto itId = _flatId.find(id);
	if (itId == _flatId.end())
	{
		throw std::logic_error("WRONG_ID");
	}
}