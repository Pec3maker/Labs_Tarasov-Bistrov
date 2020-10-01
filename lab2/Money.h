#pragma once
#include "Pair.h"

class Money : public Pair
{
private:
	const int MAX_SECOND = 100;
public:
	Money() : Pair() {}
	Money(int _firstInt, int _secondInt);
	virtual Money* Plus(const Pair& source) override;
	virtual Money* Minus(const Pair& source) override;
	virtual string GetPair() const override;
};
