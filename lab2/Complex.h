#pragma once
#include "Pair.h"

class Complex : public Pair
{
public:
	Complex() : Pair() {}
	Complex(int _firstInt, int _secondInt) : Pair(_firstInt, _secondInt) {}
	virtual string GetPair() const override;
};