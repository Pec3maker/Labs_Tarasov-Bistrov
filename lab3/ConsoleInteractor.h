#include <iostream>
#include "Operators.h"
#include "Factory.h"

using std::string;

class ConsoleInteractor
{
public:
	ConsoleInteractor();
	~ConsoleInteractor();

	void Init() const;
private:
	int GetIndex(const string& name) const;
	void Help() const;
	void CreateShape() const;
	void DeleteShape(const string& name) const;
	void PrintShape() const;
	void DelShape() const;
	void Compare() const;
	void IsIntersect() const;
	void Move() const;
	void Rotate() const;
	void GetArea() const;
	void GetCenter() const;

	Shape** _cases = nullptr;
	string* _names = nullptr;
	int _count = 0;
	const int COUNT_POINTS = 4;
};