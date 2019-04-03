#include "pch.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;
//indeksy zaczynaja się od cyfry "0"
//nie stosujemy znaków białych przy wypisywaniu umiejetnosci
//umiejetnosci wypisujemy np: szybkosc[15]
//zawodników i drużyny dodajemy sami, oraz sami ich tez zamieniamy i wyświetlamy wybierajac opcje z menu (1-6)
class player // klasa  zawodnika
{
public:
	player(string imie, string nazwisko, int wzrost, vector<string> umiejetnosci);
	player(const player &);
	void wyswietl();
private:
	string imie;
	string nazwisko;
	int wzrost;
	vector<string> umiejetnosci;
};

player::player(string imie, string nazwisko, int wzrost, vector<string> umiejetnosci) {
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->wzrost = wzrost;
	this->umiejetnosci = umiejetnosci;
}

player::player(const player &z) {
	imie = z.imie;
	nazwisko = z.nazwisko;
	wzrost = z.wzrost;
	umiejetnosci = z.umiejetnosci;
}

void player::wyswietl() {
	cout << imie << "\t" << nazwisko << "\t\t" << wzrost << "\t";
	for (int i = 0; i < umiejetnosci.size(); i++) {
		cout << umiejetnosci[i]  << "\t";
	}
	cout << endl;
}



class Team // klasa druzyny
{
public:
	Team(string nazwa);
	Team(const Team &);
	void dodajZawodnika();
	void wyswietl();
	void wyswietlZawodnika(int index);
	void zmienZawodnika(int index);
private:
	vector<player> zawodnicy;
	string nazwa;
};

Team::Team(string nazwa) {
	this->nazwa = nazwa;
}
Team::Team(const Team &d) {
	for (int i = 0; i < d.zawodnicy.size(); i++) {
		player temp(d.zawodnicy[i]);
		zawodnicy.push_back(temp);
	}
}
void Team::dodajZawodnika() {
	string imie, nazwisko;
	int wzrost;
	vector<string> umiejetnosci;
	int liczbaUmiejetnosci = 0;

	cout << "podaj imie zawodnika: ";
	cin >>  imie;
	cout << "podaj nazwisko zawodnika: ";
	cin >>  nazwisko;
	cout << "podaj wzrost zawodnika: ";
	cin >>  wzrost;
	cout << "podaj liczbe umiejtnosci: ";
	cin >>  liczbaUmiejetnosci;

	string temp;
	for (int i = 0; i < liczbaUmiejetnosci; i++) {
		cout << "podaj " << i + 1 << "# umiejetnosc: ";
		cin >> temp;
		umiejetnosci.push_back(temp);
	}
	cout << endl;
	player tempZ(imie, nazwisko, wzrost, umiejetnosci);
	zawodnicy.push_back(tempZ);
}

void Team::wyswietl() {
	cout << "imie" << "\t" << "nazwisko" << "\t" << "wzorst" << "\t" << "umiejetnosc" << endl;
	for (int i = 0; i < zawodnicy.size(); i++) {
		zawodnicy[i].wyswietl();
	}
}

void Team::wyswietlZawodnika(int index) {
	cout << "imie" << "\t" << "nazwisko" << "\t" << "wzorst" << "\t" << "umiejetnosc" << endl;
	zawodnicy[index].wyswietl();
}

void Team::zmienZawodnika(int index) {
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
		cout << "podaj " << i + 1 << "# umiejetnosc: ";
		cin >> temp;
		umiejetnosci.push_back(temp);
	}
	cout << endl;
	player tempZ(imie, nazwisko, wzrost, umiejetnosci);

	zawodnicy[index] = tempZ;
}


int main()
{
	vector<Team> druzyny;
	int wybor = -1;
	int index;
	int index2;

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
			druzyny.push_back(Team(n));
			break;
		}
		case 2:
		{
			cout << "Podaj index druzyny: ";
			cin >> index;
			druzyny[index].wyswietl();
			break;
		}
		case 3:
		{
			cout << "Podaj index druzyny: ";
			cin >> index;
			druzyny[index].dodajZawodnika();
			break;
		}
		case 4:
		{
			cout << "Podaj index druzyny: ";
			cin >> index;
			cout << "Podaj index zawodnika: ";
			cin >> index2;
			druzyny[index].wyswietlZawodnika(index2);
			break;
		}
		case 5:
		{
			cout << "Podaj index druzyny: ";
			cin >> index;
			cout << "Podaj index zawodnika: ";
			cin >> index2;
			druzyny[index].zmienZawodnika(index2);
			break;
		}
		case 6:
		{
			cout << "Podaj index druzyny: ";
			cin >> index;

			Team temp(druzyny[index]);
			druzyny.push_back(temp);
			break;
		}
		}
	}



	return 0;
}