
#include "pch.h"

#include <iostream>
#include <string>
using namespace std;

class Complex
{
public:
	Complex(string, string);
	string ConvertFromSymbolic();

private:
	string  Number;
	string  Multiplier;
	
};


Complex::Complex(string  _Number, string _Multiplier)
{
	Number = _Number;
	Multiplier = _Multiplier;
}

string Complex::ConvertFromSymbolic() {
	std::string s = "";
	int CountZero = 0;
	for (int i = 0; i < Number.length(); i++)
	{
		switch (Number[i])
		{
		case'0':
		case'1':
		case'2':
		case'3':
		case'4':
		case'5':
		case'6':
		case'7':
		case'8':
		case'9':
		case'.':
			s += Number[i];
			break;

		default:

			Multiplier += Number[i];
			CountZero--;
			break;
		}
		if (CountZero > 0 || Number[i] == '.')
		{
			CountZero++;
		}
	}
	
	
	if (Multiplier == "M")
	{
		s += " 000 000";

	}
	else if (Multiplier == "B")
	{

		s += " 000 000 000";

	}
	else if (Multiplier == "T")
	{

		s += " 000 000 000 000";

	}
	else if (Multiplier == "Qa")
	{

		s += " 000 000 000 000 000";

	}
	else if (Multiplier == "Qi")
	{

		s += " 000 000 000 000 000 000";

	}
	else if (Multiplier == "Sx")
	{

		s += " 000 000 000 000 000 000 000";

	}
	else if (Multiplier == "Sp")
	{

		s += " 000 000 000 000 000 000 000 000";

	}
	else if (Multiplier == "0c")
	{

		s += " 000 000 000 000 000 000 000 000 000";

	}
	if (CountZero > 0)
	{
		s = s.substr(0, s.length() - (CountZero - 1));

		int a = s.find(".");
		if (a >= 0) s.erase(a, 1);
	}
	return s;
}

int main()
{
	Complex firstObject("9.22", "M");
	Complex secondComplexObject("4", "B");
	Complex thirdComplex("6.25","T");
	cout << firstObject.ConvertFromSymbolic() << endl;
	cout << secondComplexObject.ConvertFromSymbolic() << endl;
	cout << thirdComplex.ConvertFromSymbolic() << endl;
}

