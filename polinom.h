#pragma once
//polinom.h
#include <iostream>

//Спецификация класса
class Polinom
{
public:
	Polinom() = default;
	Polinom(int degree, double* multipliers);
	Polinom(const Polinom& source);

	//Деструктор
	~Polinom();

	double SolvePoli(double arg) const; //Вычисление значения полинома
	void SetPoli(int degree, double* multipliers); //Ввод полинома
	Polinom AddPoli(const Polinom& source); //Прибавить полином
	Polinom SubstractPoli(const Polinom& source); //Вычесть полином
	int GetDegree() const;



	//Перегрузки
	Polinom operator = (const Polinom&);
	Polinom operator + (const Polinom&) const;
	Polinom operator - (const Polinom&) const;
	Polinom operator - () const;
	double operator [] (const int index) const;
	friend std::ostream& operator << (std::ostream&, const Polinom&);

private:
	int _degree = 0;
	double* _multipliers = nullptr;
	void cpy(Polinom& target, const int degree, const double* multiplier);
};