#pragma once

#include <iostream>
#include <fstream>
#include "Register.h"

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;

class ConsoleInteractor
{
public:
	void Init();
private:
	void Help() const;
	void CreateFlat();
	void SaveProgress() const;
	void DeleteFlat();
	void PrintAllFlats() const;
	void PrintFlatById() const;
	void PrintFlatsBySpace() const;

	Register _flatRegister;

	const string _filename = "register.txt";
};