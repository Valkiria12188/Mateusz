#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
//indeksy zaczynaja się od cyfry "0"
//nie stosujemy znaków białych przy wypisywaniu umiejetnosci
//umiejetnosci wypisujemy np: szybkosc[15]
//zawodników i drużyny dodajemy sami, oraz sami ich tez zamieniamy i wyświetlamy wybierajac opcje z menu (1-6)

class zawodnik //klasa gracza
{
public:
	zawodnik(string imie, string nazwisko, int wzrost, vector<string> umiejetnosci);
	zawodnik(const zawodnik &);
	string wyswietl();
private:
	string imie;
	string nazwisko;
	int wzrost;
	vector<string> umiejetnosci;
};

zawodnik::zawodnik(string imie, string nazwisko, int wzrost, vector<string> umiejetnosci) {
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->wzrost = wzrost;
	this->umiejetnosci = umiejetnosci;
}

zawodnik::zawodnik(const zawodnik &z) {
	imie = z.imie;
	nazwisko = z.nazwisko;
	wzrost = z.wzrost;
	umiejetnosci = z.umiejetnosci;
}

string zawodnik::wyswietl() {
	string s;
	s = imie + "\t" + nazwisko + "\t" + to_string(wzrost) + "\t";
	for (int i = 0; i < umiejetnosci.size(); i++) {
		s += umiejetnosci[i] + "\t";
	}
	s += "\n";
	return s;
}



class druzyna // klasa drużyny
{
public:
	druzyna(string nazwa);
	druzyna(const druzyna &);
	void dodajZawodnika(string imie, string nazwisko, int wzrost, vector<string> umiejetnosci);
	string wyswietl();
	string wyswietlZawodnika(int index);
	void zmienZawodnika(int index, string imie, string nazwisko, int wzrost, vector<string> umiejetnosci);
private:
	vector<zawodnik> zawodnicy;
	string nazwa;
};

druzyna::druzyna(string nazwa) {
	this->nazwa = nazwa;
}
druzyna::druzyna(const druzyna &d) {
	for (int i = 0; i < d.zawodnicy.size(); i++) {
		zawodnik temp(d.zawodnicy[i]);
		zawodnicy.push_back(temp);
	}
}
void druzyna::dodajZawodnika(string imie, string nazwisko, int wzrost, vector<string> umiejetnosci) {

	zawodnik tempZ(imie, nazwisko, wzrost, umiejetnosci);
	zawodnicy.push_back(tempZ);
}

string druzyna::wyswietl() {
	string s;
	s = "imie\tnazwisko\twzorst\tumiejetnosc\n";
	for (int i = 0; i < zawodnicy.size(); i++) {
		s += zawodnicy[i].wyswietl();
	}
	return s;
}

string druzyna::wyswietlZawodnika(int index) {
	string s;
	s = "imie\tnazwisko\twzorst\tumiejetnosc\n";
	s += zawodnicy[index].wyswietl();
	return s;
}

void druzyna::zmienZawodnika(int index, string imie, string nazwisko, int wzrost, vector<string> umiejetnosci) {


	/*cout << "podaj imie zawodnika: ";
	cin >> imie;
	cout << "podaj nazwisko zawodnika: ";
	cin >> nazwisko;
	cout << "podaj wzrost zawodnika: ";
	cin >> wzrost;
	cout << "podaj liczbe umiejtnosci: ";
	cin >> liczbaUmiejetnosci;*/

	zawodnik tempZ(imie, nazwisko, wzrost, umiejetnosci);

	zawodnicy[index] = tempZ;
}


/*
string imie, nazwisko;
int wzrost;
vector<string> umiejetnosci;
int liczbaUmiejetnosci = 0;

cout << "podaj imie zawodnika: ";
cin >> imie;
cout << "podaj nazwisko zawodnika: ";
cin >> nazwisko;
cout << "podaj wzrost zawodnika: ";
cin >> wzrost;
cout << "podaj liczbe umiejtnosci: ";
cin >> liczbaUmiejetnosci;

string temp;
for (int i = 0; i < liczbaUmiejetnosci; i++) {
cout << "podaj " << i+1 << "# umiejetnosc: ";
cin >> temp;
umiejetnosci.push_back(temp);
}
cout << endl;

*/

int main()
{
	vector<druzyna> druzyny;
	int wybor = -1;
	int index;
	int index2;

	string imie, nazwisko;
	int wzrost;
	vector<string> umiejetnosci;
	int liczbaUmiejetnosci = 0;



	while (wybor != 0)
	{
		cout << "----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|1)Dodaj druzyne  2)Wysietl druzyne  3)Dodaj zawodnika  4)Wysietl zwodnika  5)zmien zawodnika  6)Klonuj druzyne|" << endl;
		cout << "----------------------------------------------------------------------------------------------------------------" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
		{
			string n;
			cout << "podaj nazwe druzyny: ";
			cin >> n;
			druzyny.push_back(druzyna(n));
			break;
		}
		case 2:
		{
			cout << "Podaj index druzyny: ";
			cin >> index;
			cout << druzyny[index].wyswietl();
			break;
		}
		case 3:
		{
			cout << "Podaj index druzyny: ";
			cin >> index;
			cout << "podaj imie zawodnika: ";
			cin >> imie;
			cout << "podaj nazwisko zawodnika: ";
			cin >> nazwisko;
			cout << "podaj wzrost zawodnika: ";
			cin >> wzrost;
			cout << "podaj liczbe umiejtnosci: ";
			cin >> liczbaUmiejetnosci;

			string temp;
			for (int i = 0; i < liczbaUmiejetnosci; i++) {
				cout << "podaj " << i + 1 << "# umiejetnosc: ";
				cin >> temp;
				umiejetnosci.push_back(temp);
			}
			druzyny[index].dodajZawodnika(imie, nazwisko, wzrost, umiejetnosci);
			umiejetnosci.clear();
			break;
		}
		case 4:
		{
			cout << "Podaj index druzyny: ";
			cin >> index;
			cout << "Podaj index zawodnika: ";
			cin >> index2;
			cout << druzyny[index].wyswietlZawodnika(index2);
			break;
		}
		case 5:
		{
			cout << "Podaj index druzyny: ";
			cin >> index;
			cout << "Podaj index zawodnika: ";
			cin >> index2;
			cout << "podaj imie zawodnika: ";
			cin >> imie;
			cout << "podaj nazwisko zawodnika: ";
			cin >> nazwisko;
			cout << "podaj wzrost zawodnika: ";
			cin >> wzrost;
			cout << "podaj liczbe umiejtnosci: ";
			cin >> liczbaUmiejetnosci;

			string temp;
			for (int i = 0; i < liczbaUmiejetnosci; i++) {
				cout << "podaj " << i + 1 << "# umiejetnosc: ";
				cin >> temp;
				umiejetnosci.push_back(temp);
			}
			druzyny[index].zmienZawodnika(index2, imie, nazwisko, wzrost, umiejetnosci);
			umiejetnosci.clear();
			break;
		}
		case 6:
		{
			cout << "Podaj index druzyny: ";
			cin >> index;

			druzyna temp(druzyny[index]);
			druzyny.push_back(temp);
			break;
		}
		}
	}



	return 0;
}