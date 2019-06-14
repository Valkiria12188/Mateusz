#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <time.h>


using namespace std;

//---------------------klasa Matrix--------------------------
class Matrix {
	int rows, cols;
	vector<vector<double>> matrix;

public:
	Matrix(int irows, int icols);
	Matrix(string fileName);
	int getRows();
	int getCols();
	void setNumber(int irow, int icol, double value);
	string displayField(int irow, int icol);
	string displayRow(int irow);
	string displayCol(int icol);
	string displayMatrix();
	void addToAllElements(double number);
	void transposition();
	string formatToFile();
};

Matrix::Matrix(int irows, int icols) 
{											// tworzenie macierzy wypelnionej zerami
	rows = irows;
	cols = icols;
	matrix.resize(irows, std::vector<double>(icols, 0.0));
}

int Matrix::getRows()
{
	return rows;
}

int Matrix::getCols()
{
	return cols;
}

void Matrix::setNumber(int irow, int icol, double value)
{											// ustawić wartość danego pola w macierzy
	matrix[irow][icol] = value;
}

string Matrix::displayField(int irow, int icol)
{											// wyświetlanie wartości danego pola w macierzy
	return to_string(matrix[irow][icol]);
}

string Matrix::displayRow(int irow)
{											// wyświetlanie danego wiersza z macierzy
	string answer = "|";
	for (size_t i = 0; i < matrix[irow].size(); i++)
	{
		answer += to_string(matrix[irow][i]) + " | ";
	}
	return answer + "\n";
}

string Matrix::displayCol(int icol)
{									 // wyświetlanie podanej kolumny z macierzy
	string answer = "| ";
	for (int i = 0; i < rows; i++)
	{
		answer += to_string(matrix[i][icol]) + " | ";
	}
	return answer + "\n";
}

string Matrix::displayMatrix() 
{									// wyświetlanie całej macierzy
	string answer;
	for (int i = 0; i < rows; i++)
	{
		answer += displayRow(i);
	}
	return answer + "\n";
}

void Matrix::addToAllElements(double number)
{									// dodawanie wartości wszystkim elementom
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] += number;
		}
	}
}

void Matrix::transposition() 
{										//transponowanie
	vector<vector<double>> temp;
	temp.resize(cols, vector<double>(rows));
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			temp[i][j] = matrix[j][i];
		}
	}
	rows = temp.size();
	cols = temp[0].size();
	matrix.swap(temp);

}

string Matrix::formatToFile() 
{
	stringstream answer;
	int counter = 0;
	for (int i = 0; i < rows; i++) 
	{
		counter++;
		for (int j = 0; j < cols; j++) 
		{
			answer << to_string((int)matrix[i][j]);
			if (j != cols - 1)
			{
				answer << ';';
			}
		}
		if (counter != rows)
		{
			answer << endl;
		}
	}
	return answer.str();
}



Matrix::Matrix(string fileName)				// macierz z pliku
{
	
	ifstream file(fileName);
	vector<string> lines;					// zawarcie kazdej lini z pliku
	if (!file)
	{
		cout << "Blad odczytu pliku! " << endl;
	}
	else
	{
		while (!file.eof())
		{
			string input;
			getline(file, input);
			lines.push_back(input);
		}
	}
	rows = lines.size();
	for (int i = 0; i < rows; i++) 
	{ // kasowanie z wierszy znakow nie bedacych cyframi
		for (size_t j = 0; j < lines[i].size(); j++) 
		{
			if (isdigit(lines[i][j]) == 0) 
			{
				lines[i].erase(lines[i].begin() + j);
			}
		}
	}

	cols = lines[0].size();
	matrix.resize(rows, vector<double>(cols)); // ustawienie rozmiaru macierzy

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) 
		{
			string temp(1, lines[i][j]); // konwersja z char na string
			matrix[i][j] = stoi(temp); // konwersja ze string na int (double w macierzach)
		}
	}

}



string print_time();

int main()
{
	//pierwsza macierz + zmiany poszczególnych wartości
	Matrix *matrix = new Matrix("matrix.txt");
	cout << "Wczytana macierz z pliku  \n" + matrix->displayMatrix();
	matrix->setNumber(0, 0, 9);
	matrix->setNumber(3, 2, 9);
	cout << "Wczytana macierz z pliku ze zmienionymi wartosciami \n" + matrix->displayMatrix();
	stringstream fileOne;
	fileOne << "matrix1_ " << print_time() << ".txt";
	ofstream outfileOne(fileOne.str());
	outfileOne << matrix->formatToFile();
	outfileOne.close();
	
	//druga macierz + tranzpozycja
	Matrix *matrix1 = new Matrix(fileOne.str());
	cout << "Wczytana druga macierz \n" + matrix1->displayMatrix();
	
	matrix1->transposition();
	cout << "Transponowana druga macierz  \n" + matrix1->displayMatrix();
	
	stringstream fileTwo;
	fileTwo << "matrix2_ " << print_time() << ".txt";
	ofstream outfileTwo(fileTwo.str());
	outfileTwo << matrix1->formatToFile();
	outfileTwo.close();

	//trzecia macierz + każdy element ma dodaną wartosc
	Matrix *matrix2 = new Matrix(fileTwo.str());
	cout << "Wczytana trzecia macierz \n" + matrix2->displayMatrix();
	matrix2->addToAllElements(4);
	cout << "Wczytana trzecia macierz - kazdy element +4 \n" + matrix2->displayMatrix();
	stringstream fileThree;
	fileThree << "marix3_ " << print_time() << ".txt";
	ofstream outfileThree(fileThree.str());
	return(0);
}

string print_time() //czas w nazwie nowo zapisanego pliku
{
	time_t t = time(0);
	struct tm now;
	localtime_s(&now, &t);// wersja VS , gdzie indziej prawdopodobnie localtime
	stringstream timeStr;
	timeStr << now.tm_hour <<";"<< now.tm_min << ";" << now.tm_sec;
	return  timeStr.str();
}
