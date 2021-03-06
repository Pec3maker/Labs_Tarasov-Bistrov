#pragma once
#include "polinom.h"
//interface.h

class Interface 
{
public:
	Interface();
	~Interface();

	void Init() const;
private:
	void CreatePoli() const;
	void DeletePoli(const std::string name) const;
	void Help() const;
	void Minus() const;
	void Plus() const;
	int GetIndex(const std::string name) const;
	void EditPoli() const;
	void PrintPoli() const;
	void GetMultiplier() const;
	void SignInversion() const;
	void SolvePolinom() const;
	void GetDegree() const;
	void DelPolinom() const;

	std::string* _names = nullptr;
	Polinom* _cases = nullptr;
};