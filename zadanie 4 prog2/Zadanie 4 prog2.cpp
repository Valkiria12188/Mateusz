#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
# include <istream>
# include <fstream>
# include <sstream>
# include <ctime >
#include <locale.h>  
using namespace std;


string pokaz_czas();
//________________________________________________________________________________________________________________________________________________________________________________
class zawodnik //klasa gracza
{
public:
	zawodnik(string imie, string nazwisko, string wzrost, string umiejetnosc1, string umiejetnosc2, string umiejetnosc3);
	zawodnik(const zawodnik &);
	zawodnik(string);
	~zawodnik() {};
	void wyswietl();
	void zamiana_zawodnika(zawodnik *);
	vector <string> zawodnik_vector;
	string imie_zawodnika();
private:

};

zawodnik::zawodnik(string imie, string nazwisko, string wzrost, string umiejetnosc1, string umiejetnosc2, string umiejetnosc3)
{
	zawodnik_vector.push_back(imie);
	zawodnik_vector.push_back(nazwisko);
	zawodnik_vector.push_back(wzrost);
	zawodnik_vector.push_back(umiejetnosc1);
	zawodnik_vector.push_back(umiejetnosc2);
	zawodnik_vector.push_back(umiejetnosc3);
}

zawodnik::zawodnik(const zawodnik &z)
{
	zawodnik_vector = z.zawodnik_vector;
}

void zawodnik::wyswietl()  //metoda wypisania danych graczy
{
string dane = "Imie: " + zawodnik_vector[0] + " Nazwisko: " + zawodnik_vector[1] + " Wzrost: " + zawodnik_vector[2] + " umiejetnosc 1: " + zawodnik_vector[3]
+ " umiejetnosc 2: " + zawodnik_vector[4] + " umiejetnosc 3: " + zawodnik_vector[5];
cout << dane << endl;
}


zawodnik::zawodnik(string lineAsString)					// odczyanie danych zwodnika z pliku 	 
{
	stringstream line(lineAsString);
	string str;
	while (getline(line, str, ';'))
	{
		zawodnik_vector.push_back(str);
	}
}

void zamiana_zawodnika(zawodnik *x)  // metoda ktora wymienia wybranego gracza z druzyny odczytanej z pliku ( czwarta druzyna)
{
	cout << "!!Zmiana zawodnika drużyny Boston!!" << endl;
	cout << "!!Kyrie Irving schodzi z boiska!!" << endl;
	cout << "Podaj imie: ";
	getline(cin, x-> zawodnik_vector[0]);
	cout << "Podaj nazwisko: ";
	getline(cin, x-> zawodnik_vector[1]);
	cout << "Podaj wzrost: ";
	getline(cin, x-> zawodnik_vector[2]);
	cout << "Podaj umiejetnosc nr 1: ";
	getline(cin, x-> zawodnik_vector[3]);
	cout << "Podaj umiejetnosc nr 2: ";
	getline(cin, x-> zawodnik_vector[4]);
	cout << "Podaj umiejetnosc nr 3: ";
	getline(cin, x-> zawodnik_vector[5]);
}

string zawodnik::imie_zawodnika()
{
	return zawodnik_vector[0];
}

//________________________________________________________________________________________________________________________________________________________________________________
class druzyna // klasa drużyny
{
public:
	druzyna(string, zawodnik*);
	druzyna(const druzyna &, string);
	druzyna(string, zawodnik*, zawodnik*, zawodnik*, zawodnik*, zawodnik*);
	vector<zawodnik *> zawodnik_vector;
	void wyswietl_druzyne(void);
	~druzyna() {};
	vector<zawodnik *> druzyna_zawodnicy;
	void zapis_do_pliku();
	void gracz_wybrany(string);
	druzyna(string, string);
private:
	string _druzyna;
};
druzyna::druzyna(string nazwa, zawodnik *zawodnik1)
{
	_druzyna = nazwa;
	druzyna_zawodnicy.push_back(zawodnik1);
}

druzyna::druzyna(string nazwa, zawodnik *zawodnik0, zawodnik *zawodnik1, zawodnik *zawodnik2, zawodnik *zawodnik3, zawodnik *zawodnik4)
{
	_druzyna = nazwa;
	druzyna_zawodnicy.push_back(zawodnik0);
	druzyna_zawodnicy.push_back(zawodnik1);
	druzyna_zawodnicy.push_back(zawodnik2);
	druzyna_zawodnicy.push_back(zawodnik3);
	druzyna_zawodnicy.push_back(zawodnik4);
}
druzyna::druzyna(const druzyna &d, string nowa_nazwa) 
{
	_druzyna = nowa_nazwa;
	druzyna_zawodnicy = d.druzyna_zawodnicy;
}


void druzyna::wyswietl_druzyne(void) 
{																// wyswietlenie druzyny
	cout << "\t\tZawodnicy drużyny: " << _druzyna << endl << endl;
	for (int i = 0; i < druzyna_zawodnicy.size(); i++)
	{
		druzyna_zawodnicy[i]->wyswietl();
	}
}

int main()
{
	setlocale(LC_ALL, "polish");// polskie znaki

	zawodnik Stephen("Stephen", "Curry", "186", "speed: 100", "shot:90", "jump: 75");  //zawodnicy pierwszej druzyny
	zawodnik Kevin("Kevin", "Durant", "200", "speed: 90", "shot: 95", "jump: 90");
	zawodnik DeMarcus("DeMar", "Cusins", "205", "speed:75", "shot: 80", "jump: 100");
	zawodnik Klay("Klay", "Thompson", "175", "speed: 95", "shot: 90", "jump: 80");
	zawodnik Draymond("Draymond", "Green", "180", "speed: 80", "shot: 89", "jump: 85");
	
	druzyna Golden_State_Warriors("Golden State Warriors", &Stephen, &Kevin, &DeMarcus, &Klay, &Draymond);
	
	zawodnik LeBron("LeBron", "James", "199", "speed: 100", "shot: 98", "jump: 95");  //zawodnicy drugiej druzyny
	zawodnik Lonzo("Lonzo", "Ball", "180", "speed: 85", "shot: 90", "jump: 84");
	zawodnik Brandon("Brand", "Ingram", "190", "speed: 80", "shot: 78", "jump: 95");
	zawodnik Kyle("Kyle", "Kuzma", "184", "speed: 80", "shot: 85", "jump: 80");
	zawodnik Rajon("Rajon", "Rondo", "170", "speed: 82", "shot: 90", "jump: 89");
	
	druzyna Los_Angeles_Lakers("Los Angeles Lakers", &LeBron, &Lonzo, &Brandon, &Kyle, &Rajon);

	druzyna  Kopia_druzyny_nr2(Los_Angeles_Lakers, "Kopia druzyny nr 2");	  // kopia druzyny drugiej, ktora staje sie trzecią drużyną
	
	cout << " Wypisanie czterech drużyn." << endl;  // Wypisanie czterech drużyn ( w tym jedna z pliku)
	cout << "Podaj nazwe pliku do odczytu (plik.txt): ";
	string nazwapliku;
	getline(cin, nazwapliku);
	druzyna Boston("Boston", nazwapliku);

	cout << "_____________________________________________________________________________________________________________________" << endl;
	cout << "_____________________________________________________________________________________________________________________" << endl;
	Golden_State_Warriors.wyswietl_druzyne();
	cout << "_____________________________________________________________________________________________________________________" << endl;
	cout << "_____________________________________________________________________________________________________________________" << endl;
	Los_Angeles_Lakers.wyswietl_druzyne();
	cout << "_____________________________________________________________________________________________________________________" << endl;
	cout << "_____________________________________________________________________________________________________________________" << endl;
	Kopia_druzyny_nr2.wyswietl_druzyne();
	cout << "_____________________________________________________________________________________________________________________" << endl;
	cout << "_____________________________________________________________________________________________________________________" << endl;
	Boston.wyswietl_druzyne();
	cout << "_____________________________________________________________________________________________________________________" << endl;
	cout << "_____________________________________________________________________________________________________________________" << endl;

	cout << "--------------------------------------------Zmiana zawodnika---------------------------------------------------------" << endl;
	Boston.gracz_wybrany("Kyrie"); //gracz wybrany do metody zamiana_zawodnika
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Wypisanie ponownie drużyn ze zmienionym graczem: " << endl;

	cout << "_____________________________________________________________________________________________________________________" << endl;
	cout << "_____________________________________________________________________________________________________________________" << endl;
	Golden_State_Warriors.wyswietl_druzyne();
	cout << "_____________________________________________________________________________________________________________________" << endl;
	cout << "_____________________________________________________________________________________________________________________" << endl;
	Los_Angeles_Lakers.wyswietl_druzyne();
	cout << "_____________________________________________________________________________________________________________________" << endl;
	cout << "_____________________________________________________________________________________________________________________" << endl;
	Kopia_druzyny_nr2.wyswietl_druzyne();
	cout << "_____________________________________________________________________________________________________________________" << endl;
	cout << "_____________________________________________________________________________________________________________________" << endl;
	Boston.wyswietl_druzyne();
	cout << "_____________________________________________________________________________________________________________________" << endl;
	cout << "_____________________________________________________________________________________________________________________" << endl;
	Golden_State_Warriors.zapis_do_pliku(); // zapis druzyn z zawodnikami do pliku
	Los_Angeles_Lakers.zapis_do_pliku();
	Kopia_druzyny_nr2.zapis_do_pliku();
	Boston.zapis_do_pliku();
		 return 0;
}

void druzyna::gracz_wybrany(string imie)  // wybranie imienia gracza do zamiany (metody zamiana_zawodnika)
{
	int i, x = 0;
	for (i = 0; i < druzyna_zawodnicy.size(); i++)
	{
		if (druzyna_zawodnicy[i]->imie_zawodnika() == imie)
		{
			zamiana_zawodnika(druzyna_zawodnicy[i]);
			x = 1;
		}
		if (x == 1) break;
	}
	if (x == 0) 
	{
		cout << "Nie ma takiego zawodnika w zespole" << endl;
	}
}

druzyna::druzyna(string nazwadruzyny, string nazwapliku) {

	ifstream inputFile(nazwapliku);
	if (inputFile.fail()) {
		cout << "Brak pliku";
		exit(1);
	}
	else {
		_druzyna = nazwadruzyny;
		string lineAsString;
		while (!inputFile.eof())
		{
			inputFile >> lineAsString;
			druzyna_zawodnicy.push_back(new zawodnik(lineAsString));
		}
		inputFile.close();
	}
}
//metoda zapisu do pliku
void druzyna::zapis_do_pliku()
{
	string nazwapliku = _druzyna + "_" + pokaz_czas() + ".txt";
	ofstream outputFile(nazwapliku);
	if (outputFile.fail())
	{
		cout << " Nie moge utworzyc pliku";
		exit(1);
	}
	else
	{
		int i, j;
		string lineAsString;
		for (i = 0; i < druzyna_zawodnicy.size(); i++) 
		{
			lineAsString = "";
			for (j = 0; j < druzyna_zawodnicy[i]->zawodnik_vector.size(); j++)
			{
				if (j == druzyna_zawodnicy[i]->zawodnik_vector.size() - 1)  lineAsString += druzyna_zawodnicy[i]->zawodnik_vector[j];
				else  lineAsString += druzyna_zawodnicy[i]->zawodnik_vector[j] + ";";

			}
			outputFile << lineAsString << endl;
		}
		outputFile.close();
	}
}
//czas
	string pokaz_czas() 
	{
		time_t t = time(0);
		struct tm now;
		localtime_s(&now, &t);// wersja VS , gdzie indziej prawdopodobnie localtime
		stringstream timeStr;
		timeStr << now.tm_hour << now.tm_min << now.tm_sec;
		return  timeStr.str();								
	}












