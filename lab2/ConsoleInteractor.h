#include "Pair.h"
#include "Complex.h"
#include "Money.h"

class ConsoleInteractor
{
public:
	ConsoleInteractor();
	~ConsoleInteractor();

	void Init() const;
private:
	int GetIndex(const string& name) const;
	void Minus() const;
	void Plus() const;
	void Help() const;
	void CreatePair() const;
	void DeletePair(const string& name) const;
	void PrintPair() const;
	void DelPair() const;

	Pair** _cases = nullptr;
	string* _names = nullptr;
	int _count = 0;
};