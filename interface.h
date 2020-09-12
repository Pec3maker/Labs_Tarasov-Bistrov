//interface.h
#pragma once
#include "polinom.h"

class Interface 
{
public:
	Interface() = default;
	~Interface();

	void Init();
private:
	void CreatePoli();
	void DeletePoli(std::string name);
	void Help();
	void Minus();
	void Plus();
	int GetIndex(std::string name);
	void EditPoli(std::string name);

	std::string* _names = nullptr;
	Polinom* _cases = nullptr;
};
