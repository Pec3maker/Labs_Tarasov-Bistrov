#pragma once
//polinom.h
#include <iostream>

//������������ ������
class Polinom
{
public:
	Polinom() = default;
	Polinom(int degree, double* multipliers);
	Polinom(const Polinom& source);

	//����������
	~Polinom();

	double SolvePoli(double arg) const; //���������� �������� ��������
	void SetPoli(int degree, double* multipliers); //���� ��������
	Polinom AddPoli(const Polinom& source); //��������� �������
	Polinom SubstractPoli(const Polinom& source); //������� �������
	int GetDegree() const;



	//����������
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