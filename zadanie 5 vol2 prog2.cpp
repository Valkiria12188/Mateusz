#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
# include <istream>
# include <fstream>
# include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <algorithm>
using namespace std;

//---------------------klasa Item---------------------------
class Item
{
public:
	string name;
	int value;
	Item(string, int);
	~Item();
};

Item::Item(string name_input, int value_input)
{
	name = name_input;
	value = value_input;
}

Item::~Item()
{
}


//---------------------klasa room-----------------------------
class Room
{
public:
	string description;
	int x, y;
	Item* item;
	Room *neighbourN;
	Room *neighbourW;
	Room *neighbourE;
	Room *neighbourS;
	Room(int, int);
	void getDescription(string);
	void getNeighbourN(Room *);
	void getneighbourE(Room*);
	void getNeighbourS(Room*);
	void getNeighbourW(Room*);
	bool checkItem();
	string returnItem();
	~Room();
};

Room::Room(int x_input, int y_input)
{
	
	x = x_input;
	y = y_input;
}

void  Room::getDescription(string description_input)
{
	description = description_input;
}

void Room::getNeighbourN(Room *neighbourN_input)
{
	*neighbourN = *neighbourN_input;
}

void Room ::getneighbourE(Room *neighbourE_input)
{
	*neighbourE = *neighbourE_input;
}

void Room::getNeighbourS(Room *neighbourS_input)
{
	*neighbourS = *neighbourS_input;
}

void Room::getNeighbourW(Room *neighbourW_input)
{
	*neighbourW = *neighbourW_input;
}

bool Room::checkItem()
{
	if (item != NULL)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

string Room::returnItem()
{
	return item->name;
}

Room::~Room()
{
}

//-----------------------main----------------------------------------------------------------
int main()
{
	srand(time(NULL));

	Room* room_1 = new Room(0, 0);
	Room* room_2 = new Room(0, 1);
	Room* room_3 = new Room(0, 2);
	Room* room_4 = new Room(0, 3);
	Room* room_5 = new Room(0, 4);
	Room* room_6 = new Room(0, 5);
	Room* room_7 = new Room(1, 0);
	Room* room_8 = new Room(1, 1);
	Room* room_9 = new Room(1, 2);
	Room* room_10 = new Room(1, 3);
	Room* room_11 = new Room(1, 4);
	Room* room_12 = new Room(1, 5);
	Room* room_13 = new Room(2, 0);
	Room* room_14 = new Room(2, 1);
	Room* room_15 = new Room(2, 2);
	Room* room_16 = new Room(2, 3);
	Room* room_17 = new Room(2, 4);
	Room* room_18 = new Room(2, 5);
																												// wypisanie sasiadów każdego z pomieszczeń
	room_1->neighbourN = NULL;     room_1->neighbourE = room_2;   room_1->neighbourS = NULL;     room_1->neighbourW = NULL;     room_1->item = NULL;
	room_2->neighbourN = NULL;     room_2->neighbourE = NULL;     room_2->neighbourS = room_7;   room_2->neighbourW = room_1;   room_2->item = NULL;
	room_3->neighbourN = NULL;     room_3->neighbourE = NULL;     room_3->neighbourS = room_9;   room_3->neighbourW = NULL;     room_3->item = NULL;
	room_4->neighbourN = NULL;     room_4->neighbourE = room_5;   room_4->neighbourS = room_11;  room_4->neighbourW = NULL;     room_4->item = NULL;
	room_5->neighbourN = NULL;     room_5->neighbourE = room_6;   room_5->neighbourS = NULL;     room_5->neighbourW = room_4;   room_5->item = NULL;
	room_6->neighbourN = NULL;     room_6->neighbourE = NULL;     room_6->neighbourS = room_12;  room_6->neighbourW = room_5;   room_6->item = NULL;
	room_7->neighbourN = room_2;   room_7->neighbourE = room_8;   room_7->neighbourS = room_14;  room_7->neighbourW = NULL;     room_7->item = NULL;
	room_8->neighbourN = NULL;     room_8->neighbourE = room_9;   room_8->neighbourS = NULL;     room_8->neighbourW = room_7;   room_8->item = NULL;
	room_9->neighbourN = room_3;   room_9->neighbourE = room_10;  room_9->neighbourS = room_15;  room_9->neighbourW = room_8;   room_9->item = NULL;
	room_10->neighbourN = NULL;    room_10->neighbourE = room_11; room_10->neighbourS = NULL;    room_10->neighbourW = room_9;  room_10->item = NULL;
	room_11->neighbourN = room_4;  room_11->neighbourE = NULL;    room_11->neighbourS = room_16; room_11->neighbourW = room_10; room_11->item = NULL;
	room_12->neighbourN = room_6;  room_12->neighbourE = NULL;    room_12->neighbourS = room_18; room_12->neighbourW = NULL;    room_12->item = NULL;
	room_13->neighbourN = NULL;    room_13->neighbourE = room_14; room_13->neighbourS = NULL;    room_13->neighbourW = NULL;    room_13->item = NULL;
	room_14->neighbourN = room_7;  room_14->neighbourE = NULL;    room_14->neighbourS = NULL;    room_14->neighbourW = room_13; room_14->item = NULL;
	room_15->neighbourN = room_9;  room_15->neighbourE = NULL;    room_15->neighbourS = NULL;    room_15->neighbourW = NULL;    room_15->item = NULL;
	room_16->neighbourN = room_11; room_16->neighbourE = room_17; room_16->neighbourS = NULL;    room_16->neighbourW = NULL;    room_16->item = NULL;
	room_17->neighbourN = NULL;    room_17->neighbourE = room_18; room_17->neighbourS = NULL;    room_17->neighbourW = room_16; room_17->item = NULL;
	room_18->neighbourN = room_12; room_18->neighbourE = NULL;    room_18->neighbourS = NULL;    room_18->neighbourW = room_17; room_18->item = NULL;

	Room *house[3][6];

	vector <Room*> rooms;									//wektor pokojów
	rooms.push_back(room_1);
	rooms.push_back(room_2);
	rooms.push_back(room_3);
	rooms.push_back(room_4);
	rooms.push_back(room_5);
	rooms.push_back(room_6);
	rooms.push_back(room_7);
	rooms.push_back(room_8);
	rooms.push_back(room_9);
	rooms.push_back(room_10);
	rooms.push_back(room_11);
	rooms.push_back(room_12);
	rooms.push_back(room_13);
	rooms.push_back(room_14);
	rooms.push_back(room_15);
	rooms.push_back(room_16);
	rooms.push_back(room_17);
	rooms.push_back(room_18);

	for (int j = 0; j < 3; j++)                                 
	{
		for (int k = 0; k < 6; k++)
		{
			for (int i = 0; i < 18; i++)
			{
				if (j == rooms[i]->x && k == rooms[i]->y)
				{
					house[j][k] = rooms[i];
				}
			}
		}
	}
	
	cout << "Standard room" << endl;

	for (int j = 0; j < 3; j++)                                         
	{																//podstawowy schemat pomieszczenia potrzebny do zadania
		for (int k = 0; k < 6; k++)
		{
			if (k == 0 && j == 1 && house[j][k]->neighbourW == NULL) cout << "X";
			cout << "#";
			if (house[j][k]->neighbourE == NULL && k != 5)
			{
				cout << "X";
			}
		}
		cout << endl;
	}
	cout << endl;

	vector <Room*> v;                                              // schemat drogi przez pomieszczenia
	v.push_back(house[0][0]);          v.push_back(v[0]->neighbourE);
	v.push_back(v[1]->neighbourS);     v.push_back(v[2]->neighbourS);
	v.push_back(v[3]->neighbourW);     v.push_back(v[4]->neighbourE);
	v.push_back(v[5]->neighbourN);     v.push_back(v[6]->neighbourE);
	v.push_back(v[7]->neighbourE);     v.push_back(v[8]->neighbourS);
	v.push_back(v[9]->neighbourN);     v.push_back(v[10]->neighbourN);
	v.push_back(v[11]->neighbourS);    v.push_back(v[12]->neighbourE);
	v.push_back(v[13]->neighbourE);    v.push_back(v[14]->neighbourN);
	v.push_back(v[15]->neighbourE);    v.push_back(v[16]->neighbourE);
	v.push_back(v[17]->neighbourW);    v.push_back(v[18]->neighbourW);
	v.push_back(v[19]->neighbourS);    v.push_back(v[20]->neighbourS);
	v.push_back(v[21]->neighbourE);    v.push_back(v[22]->neighbourE);

	Item* Axe = new Item("Shinobi Axe", 10);
	Item* Sabimaru = new Item("Golden Sabimaru", 20);
	Item* Spear = new Item("Red Spear", 50);

	int temp;                                                      
	temp = rand() % 24;
	v[temp]->item = Axe;

	do
	{															//losowanie pomieszczen dla przedmiotów i wyszukiwanie ilości kroków potrzebnych do zdobycia przedmiotów
		temp = rand() % 24;
	} while (v[temp]->checkItem());
		v[temp]->item = Sabimaru;
	do
	{
		temp = rand() % 24;
	} while (v[temp]->checkItem());
		v[temp]->item = Spear;

	cout << "Item list with steps: " << endl;
	for (int i = 0; i < 24; i++)
	{
		if (v[i]->checkItem())
		{
			cout << "-----Step [" << i + 1 << "]" << " The name of the item: " << v[i]->returnItem() << endl;
		}
	}
	cout << endl;
	cout << "Room with items" << endl;								
	
	for (int j = 0; j < 3; j++)												 //wyświelenie przedmiotów(pierwsza litera)                               
	{
		for (int k = 0; k < 6; k++)
		{
			if (k == 0 && j == 1 && house[j][k]->neighbourW == NULL) 
			{ 
				cout << "X";
			}
			if (house[j][k]->checkItem() == 0) 
			{ 
				cout << "#"; 
			}
			else 
			{ 
				cout << house[j][k]->item->name[0]; 
			}
			if (house[j][k]->neighbourE == NULL && k != 5)
			{
				cout << "X";
			}
		}
		cout << endl;
	}
	

	delete room_1, room_2, room_3, room_4, room_5, room_6, room_7, room_8, room_9, room_10, room_11, room_12, room_13, room_14, room_15, room_16, room_17, room_18;
	delete  Axe, Sabimaru, Spear;
	return 0;
} 