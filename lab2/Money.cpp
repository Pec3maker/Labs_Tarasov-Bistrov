#include "Money.h"
#include <stdexcept>

Money::Money(int _firstInt, int _secondInt) : Pair(_firstInt, _secondInt)
{
	if (_secondInt > MAX_SECOND)
	{
		_firstInt += _secondInt / MAX_SECOND;
		_secondInt = _secondInt % MAX_SECOND;
	}

	if (_firstInt < 0 || _secondInt < 0)
	{
		throw std::logic_error("Less than zero\n");
	}
}

Money* Money::Plus(const Pair& source)
{
	int firstInt = GetFirstInt();
	int secondInt = source.GetSecondInt();
	_firstInt += firstInt + (_secondInt + secondInt) / MAX_SECOND;
	_secondInt = (_secondInt + secondInt) % MAX_SECOND;
	return this;
}

Money* Money::Minus(const Pair& source)
{
	int firstInt = source.GetFirstInt();
	int secondInt = source.GetSecondInt();

	_firstInt = (_firstInt > firstInt) ? _firstInt - firstInt : 0;

	if (_secondInt >= secondInt)
	{
		_secondInt -= secondInt;
	}
	else if (_firstInt)
	{
		_firstInt--;
		_secondInt = _secondInt - secondInt + MAX_SECOND;
	}
	else
	{
		_secondInt = 0;
	}

	return this;
}

string Money::GetPair() const
{

	string result = std::to_string(_firstInt) + "." + std::to_string(_secondInt) + " rub";
	return result;
}
