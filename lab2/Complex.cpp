#include "Complex.h"

string Complex::GetPair() const
{
	return std::to_string(_firstInt) + " + " + std::to_string(_secondInt) + "i";
}