
#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <exception>

using namespace std;

//------------klasa Matrix---------------------
class Matrix
{
	int rows, cols;
public:
vector<vector<double>> matrix;

public:
	Matrix(int irows, int icols);
	Matrix(string fileName);
	string displayRow(int irow);
	string displayMatrix();
	Matrix multiplyMatrix(Matrix &two);
	int returnRows();
	int returnCols();
	string displayTwo(Matrix &two);
	string formatToFile();
	Matrix addValue(int value);
	Matrix addMatrix(Matrix &two);
	Matrix substractMatrix(Matrix &two);
};
Matrix::Matrix(int irows, int icols) 
{									// tworzenie macierzy wypelnionej zerami
	rows = irows;
	cols = icols;
	matrix.resize(irows, vector<double>(icols, 0.0));
}

Matrix::Matrix(string fileName) 
{									 // macierz z pliku
	ifstream file(fileName);
	vector<string> lines;			// zawarcie kazdej lini z pliku jako wektor
	while (!file.eof()) { 
		string input;
		getline(file, input);
		lines.push_back(input);
	}

	Matrix::rows = lines.size();
	vector<double> numbers;

	for (int i = 0; i < Matrix::rows; i++)
	{ // liczby z pliku na vektor liczb
		size_t j = 0;
		string number;
		while (j <= lines[i].size()) 
		{
			if (isdigit(lines[i][j]) != 0)
			{
				number += lines[i][j];
				j++;
			}
			else {
				if (!number.empty()) 
				{
					numbers.push_back(stod(number));
					number.clear();
					j++;
				}
			}
		}
	}

	Matrix::cols = numbers.size() / rows;
	Matrix::matrix.resize(rows, vector<double>(cols));
	int iter = 0;
	int k = 0;
	while (k < cols && iter < rows) 
	{ 
		Matrix::matrix[iter][k] = numbers[k];     //wstawianie liczb z liczb wektorowych do wektora docelowego 2D
		k++; 
		if (k == cols) 
		{
			k = 0;
			iter++;
			numbers.erase(numbers.begin(), numbers.begin() + cols);
		}
	}

}

int Matrix::returnRows() 
{ 
	return rows;
}
int Matrix::returnCols()
{ 
	return cols; 
}

string Matrix::displayRow(int row) 
{ 
						// wyswietlenie pojedynczego rzedu
	string answer;
	for (int i = 0; i < Matrix::cols; i++) {
		answer += to_string(Matrix::matrix[row][i]) + " | ";
	}
	return answer;
}

string Matrix::displayMatrix()
{								 // wyswietlenie calej macierzy
	string answer;
	for (int i = 0; i < Matrix::rows; i++) 
	{
		answer += Matrix::displayRow(i) + "\n";
	}
	return answer;
}

Matrix Matrix::multiplyMatrix(Matrix &two)
{
	Matrix *multiplied = new Matrix(Matrix::rows, two.returnCols());

	if (Matrix::cols != two.returnRows()) 
	{
		throw runtime_error("Złe polaczenie. Pmaiętaj liczba kolumn w pierwszej macierzy musi odpowiadac liczbie rzedow w drugiej macierzy.\n");
	}

	for (int i = 0; i < Matrix::rows; i++) 
	{
		for (int j = 0; j < two.returnCols(); j++)
		{
			for (int k = 0; k < Matrix::cols; k++) 
			{
				multiplied->matrix[i][j] += Matrix::matrix[i][k] * two.matrix[k][j];
			}
		}
	}
	return *multiplied;
}

string Matrix::displayTwo(Matrix &two) 
{
	stringstream answer;
	int r1 = Matrix::returnRows();
	int r2 = two.returnRows();


	if (r1 < r2) 
	{
		int i = 0;
		int j = 0;
		while (j < r2) 
		{
			if (i < r1) 
			{
				answer << Matrix::displayRow(i) + "     ";
				i++;
			}
			else
			{
				string spaces;
				int length = Matrix::displayRow(0).length();
				spaces.insert(spaces.begin(), length, ' ');
				answer << spaces + "     ";
			}
			answer << two.displayRow(j);
			j++;
			answer << "\n";
		}
	}
	else if (r2 < r1) 
	{
		int i = 0;
		int j = 0;
		while (j < r1) 
		{
			answer << Matrix::displayRow(j) + "     ";
			j++;
			if (i < r2) 
			{
				answer << two.displayRow(i);
				i++;
			}
			answer << "\n";
		}
	}
	else 
	{
		for (int i = 0; i < Matrix::returnRows(); i++)
		{
			answer << Matrix::displayRow(i) + "     " + two.displayRow(i) + "\n";
		}
	}


	return answer.str();
}

string Matrix::formatToFile()
{
	stringstream answer;
	int counter = 0;
	for (int i = 0; i < Matrix::rows; i++)
	{
		counter++;
		for (int j = 0; j < Matrix::cols; j++) 
		{
			answer << Matrix::matrix[i][j];
			if (j != cols - 1)
			{
				answer << ';';
			}
		}
		if (counter != rows) 
		{
			answer <<endl;
		}
	}
	return answer.str();
}

Matrix Matrix::addValue(int value) 
{												//dodanie wartosci do macierzy
	Matrix *added_val = new Matrix(Matrix::rows, Matrix::cols);

	for (int i = 0; i < Matrix::rows; i++)
	{
		for (int j = 0; j < Matrix::cols; j++)
		{
			added_val->matrix[i][j] = Matrix::matrix[i][j] + value;
		}
	}

	return *added_val;
}

Matrix Matrix::addMatrix(Matrix &two) 
{																					//dodawanie macierzy
	if (Matrix::rows != two.returnRows() || Matrix::cols != two.returnCols()) 
	{
		throw runtime_error("Zle polaczenie. Pmaietaj liczba kolumn musi odpowiadac liczbie rzedow w drugiej macierzy\n");
	}

	Matrix *added = new Matrix(Matrix::rows, Matrix::cols);
	for (int i = 0; i < Matrix::rows; i++)
	{
		for (int j = 0; j < Matrix::cols; j++) 
		{
			added->matrix[i][j] = Matrix::matrix[i][j] + two.matrix[i][j];
		}
	}

	return *added;
}

Matrix Matrix::substractMatrix(Matrix &two)
{										//odejmowanie macierzy 					
	if (Matrix::rows != two.returnRows() || Matrix::cols != two.returnCols())
	{
		throw runtime_error("Zle polaczenie. Pmaietaj liczba kolumn musi odpowiadac liczbie rzedow w drugiej macierzy\n");
	}

	Matrix *substracted = new Matrix(Matrix::rows, Matrix::cols);
	for (int i = 0; i < Matrix::rows; i++) 
	{
		for (int j = 0; j < Matrix::cols; j++) 
		{
			substracted->matrix[i][j] = Matrix::matrix[i][j] - two.matrix[i][j];
		}
	}

	return *substracted;
}




int main()
{
	
	Matrix *matrixA = new Matrix("matrix_a.txt");
	cout << "Wczytana macierz z pliku txt  \n" + matrixA->displayMatrix();
	Matrix *matrixB = new Matrix("matrix_b.txt");
	Matrix *matrixC = new Matrix(matrixA->multiplyMatrix(*matrixB));
	
	cout << "\nMacierz A\n";
	cout << matrixA->displayMatrix();
	cout << "\nMacierz B					 Macierz C (AxB)\n";
	cout << matrixB->displayTwo(*matrixC);
	
	ofstream outfileC("matrix_c.txt");
	outfileC << matrixC->formatToFile();
	outfileC.close();

	cout << "\nProba pomnozenia zlych macierzy - C*B\n";
	try 
	{
		Matrix *err = new Matrix(matrixC->multiplyMatrix(*matrixB));
	}
	catch (int e)
	{
		cout << "\nException Nr. " << e;
	}
	catch (exception &e)
	{
		cout << "Ex.desc: " << e.what();
	}

	Matrix *matrixD = new Matrix("matrix_c.txt");
	cout << "Macierz D\n" + matrixD->displayMatrix();
	Matrix *add = new Matrix(matrixD->addValue(4));
	cout << "\nMacierz D - kazdy element + 4\n" + add->displayMatrix();

	cout << "\nMacierz E - C+D\n";
	Matrix *matrixE = new Matrix(matrixC->addMatrix(*matrixD));
	cout << matrixE->displayMatrix();

	Matrix *matrixF = new Matrix(matrixC->addMatrix(*matrixD));
	Matrix *matrixG = new Matrix(matrixE->substractMatrix(*matrixF));
	cout << "\nMacierz G - E-F\n";
	cout << matrixG->displayMatrix();

	cout << "Macierz C			                 Macierz D				         Macierz E\n";
	for (int i = 0; i < matrixC->returnRows(); i++) 
	{
		cout << matrixC->displayRow(i) + " " + matrixD->displayRow(i) + " " + matrixE->displayRow(i) + " " << endl;
	}

	cout << "\nMatrix F\n" + matrixF->displayMatrix();
	cout << "\nMatrix G\n" + matrixG->displayMatrix();

	cout << "\nProba dodania zlych macierzy - A+B\n";
	try {
		Matrix *add = new Matrix(matrixA->addMatrix(*matrixB));
	}
	catch (int e)
	{
		cout << "Exception Nr. " << e;
	}
	catch (exception &e)
	{
		cout << "Ex.desc: " << e.what();
	}
	return(0);
}