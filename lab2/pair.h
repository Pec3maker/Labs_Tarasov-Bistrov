#pragma once
#include <string>
using std::string;

class Pair
{
public:

	Pair() :_firstInt(0), _secondInt(0) {}
	Pair(const int firstInt, const int secondInt) :_firstInt(firstInt), _secondInt(secondInt) {}

	void SetPair(const int firstInt, const int secondInt);
	int GetFirstInt() const;
	int GetSecondInt() const;
	virtual Pair* Plus(const Pair& source);
	virtual Pair* Minus(const Pair& source);
	virtual string GetPair() const = 0;

protected:
	int _firstInt;
	int _secondInt;
};
