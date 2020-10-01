#include "Pair.h"

void Pair::SetPair(const int firstInt, const int secondInt) 
{
	_firstInt = firstInt;
	_secondInt = secondInt;
}

int Pair::GetFirstInt() const
{
	return _firstInt;
}

int Pair::GetSecondInt() const
{
	return _secondInt;
}

Pair* Pair::Plus(const Pair& source)
{
	_firstInt += source._firstInt;
	_secondInt += source._secondInt;
	return this;
}

Pair* Pair::Minus(const Pair& source)
{
	_firstInt += source._firstInt;
	_secondInt += source._secondInt;
	return this;
}
