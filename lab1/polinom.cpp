//polinom.cpp
#include <iostream>
#include "polinom.h"

//Определение конструкторов и методов
Polinom::Polinom(int degree, double* multipliers)
{
	_multipliers = new double[degree + 1];
	cpy(*this, degree, multipliers);
}

Polinom::Polinom(const Polinom& source)
{
	cpy(*this, source._degree, source._multipliers);
}

double Polinom::SolvePoli(double arg) const
{
	double answ = 0;
	for (int i = _degree, j = 0; i >= 0; i--, j++)
	{
		answ += _multipliers[j] * pow(arg, i); //exp(b*log(a))
	}
	return answ;
}

void Polinom::SetPoli(int degree, double* multipliers)
{
	cpy(*this, degree, multipliers);
}

Polinom Polinom::AddPoli(const Polinom& source)
{
	*this = *this + source;
	return *this;
}

Polinom Polinom::SubstractPoli(const Polinom& source)
{
	*this = *this - source;
	return *this;
}

int Polinom::GetDegree() const
{
	return _degree;
}

std::ostream& operator << (std::ostream& out, const Polinom& poli)
{
	for (int i = poli._degree, j = 0; i >= 0; i--, j++)
	{
		if (poli._multipliers[j])
		{
			out << poli._multipliers[j] << "*x^" << i;
			if (i)
			{
				out << " + ";
			}
		}
		else if (!i)
		{
			out << poli._multipliers[j];
		}
	}
	return out;
}

Polinom Polinom::operator - () const
{
	Polinom result;
	result._degree = _degree;
	result._multipliers = new double[result._degree + 1];
	for (int i = 0; i <= _degree; i++)
	{
		result._multipliers[i] = -_multipliers[i];
	}
	return result;
}

Polinom Polinom::operator + (const Polinom& source) const
{
	Polinom result;
	int delDegree = abs(_degree - source._degree);
	result._degree = (_degree > source._degree) ? _degree : source._degree;
	result._multipliers = new double[result._degree + 1];

	if (_degree > source._degree)
	{
		memcpy(result._multipliers, _multipliers, sizeof(double) * (_degree + 1));
		for (int i = delDegree, j = 0; i <= result._degree; i++, j++)
		{
			result._multipliers[i] += source._multipliers[j];
		}
	}
	else
	{
		memcpy(result._multipliers, source._multipliers, sizeof(double) * (source._degree + 1));
		for (int i = delDegree, j = 0; i <= result._degree; i++, j++)
		{
			result._multipliers[i] += _multipliers[j];
		}
	}
	return result;
}

Polinom Polinom::operator - (const Polinom& source) const
{
	return *this + (-source);
}

void Polinom::cpy(Polinom& target, const int degree, const double* multipliers)
{
	target._degree = degree;
	if (target._degree != degree || target._multipliers == nullptr)
	{
		delete[] target._multipliers;
		target._multipliers = new double[target._degree + 1];
	}
	memcpy(target._multipliers, multipliers, sizeof(double) * (target._degree + 1));
}

double Polinom::operator [] (const int index) const
{
	if (index > _degree)
	{
		throw std::out_of_range("OUT_OF_RANGE");
	}
	else
	{
		return _multipliers[index];
	}
}

Polinom Polinom::operator =(const Polinom& source)
{
	cpy(*this, source._degree, source._multipliers);
	return *this;
}

Polinom::~Polinom()
{
	delete[] _multipliers;
}