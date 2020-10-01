#pragma once
#include "Pair.h"

const int MAX_SECOND = 100;

class Money : public Pair
{
public:
	Money() : Pair() {}
	Money(int _firstInt, int _secondInt);
	virtual Money* Plus(const Pair& source) override;
	virtual Money* Minus(const Pair& source) override;
	virtual string GetPair() const override;
};
