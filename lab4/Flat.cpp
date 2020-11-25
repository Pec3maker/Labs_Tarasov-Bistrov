#include "Flat.h"

int Flat::GenerateId()
{
	static int id = 0;
	return ++id;
}
int Flat::GetSpace() const
{
	return _space;
}

int Flat::GetCountRooms() const
{
	return _countRooms;
}

int Flat::GetFloor() const
{
	return _floor;
}

const string& Flat::GetDistrict() const
{
	return _district;
}

std::ostream& operator<<(std::ostream& out, const Flat& flat)
{
	out << "Id: " << flat._id << " District: " << flat._district << " Floor: " << \
		flat._floor << " Count rooms: " << flat._countRooms << " Space: " << flat._space;

	return out;
}

bool operator<(const Flat& a, const Flat& b)
{
	return a.GetSpace() < b.GetSpace();
}

int Flat::GetId() const
{
	return _id;
}