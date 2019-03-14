// zadanie pierwsze zajecia.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.


#include "pch.h"

#include <iostream>
#include <string>


std::string ConvertFromSymbolic(std::string value);


int main(int argc, char ** argv[])
{
	std::cout << ConvertFromSymbolic("5.434B")<< std::endl;
	std::cout << ConvertFromSymbolic("4M") << std::endl;
	std::cout << ConvertFromSymbolic("54T") << std::endl;
	int x = 0;
	std::cin >> x;
	return 0;
}

std::string ConvertFromSymbolic(std::string value)
{
	
	std::string Number = "";
	std::string Multiplier = "";
	int CountZero = 0;
	for (int i = 0; i < value.length(); i++)
	{
		switch (value[i])
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
			Number += value[i];
			break;
	
		default:
			
			Multiplier += value[i];
			CountZero--;
			break;
		}
		if (CountZero > 0 || value[i] == '.') 
		{
			CountZero++;
		}
	
	}
	
	if (Multiplier == "M")
	{
		Number += " 000 000";

	}
	else if (Multiplier == "B")
	{

		Number+= "000 000 000";

	}
	else if (Multiplier == "T")
	{

		Number += " 000 000 000 000";

	}
	else if (Multiplier == "Qa")
	{

		Number += " 000 000 000 000 000";

	}
	else if (Multiplier == "Qi")
	{

		Number += " 000 000 000 000 000 000";

	}
	else if (Multiplier == "Sx")
	{

		Number += " 000 000 000 000 000 000 000";

	}
	else if (Multiplier == "Sp")
	{

		Number += " 000 000 000 000 000 000 000 000";

	}
	else if (Multiplier == "0c")
	{

		Number += " 000 000 000 000 000 000 000 000 000";

	}
	 if (CountZero >0)
	{
		 Number = Number.substr(0, Number.length() - (CountZero-1));
		

	}
	
	
	return Number;
	
}





































