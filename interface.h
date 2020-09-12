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
	void DeletePoli(std::string const name) const;
	void Help() const;
	void Minus() const;
	void Plus() const;
	int GetIndex(std::string const name) const;
	void EditPoli(std::string const name) const;

	std::string* _names = nullptr;
	Polinom* _cases = nullptr;
};
