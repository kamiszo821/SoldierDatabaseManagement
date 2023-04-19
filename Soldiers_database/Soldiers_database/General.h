#pragma once
#include "Menu.h"
class General :public Soldier
{
	string rank;
	string role;
	string name;
	string surname;
	int years_of_service;
	string birth;
public:
	string getrank() { return rank; };
	string getrole() { return role; };
	string getname() { return name; };
	string getsurname() { return surname; };
	int getyears_of_service() { return years_of_service; };
	string getbirth() { return birth; };
	General()
	{
		this->rank = "General";
		cout << "Podaj imie: ";
		string name;
		cin >> name;
		this->name = name;

		cout << "Podaj role: "; 
		string role;
		cin >> role;
		this->role = role;


		cout << "Podaj nazwisko: ";
		string surname;
		cin >> surname;
		this->surname = surname;


		cout << "Podaj lata sluzby: ";
		int years_of_service;
		cin >> years_of_service;
		this->years_of_service = years_of_service;

		cout << "Podaj date urodzenia: DD.MM.RRRR " << endl;
		string birth;
		cin >> birth;
		Menu::check_data(birth);
		this->birth = birth;

		system("cls");
	}
	General(string RANK, string ROLE, string NAME, string SURNAME, int YEARS_OF_SERVICE,string BIRTH) : rank(RANK), role(ROLE), name(NAME), surname(SURNAME), years_of_service(YEARS_OF_SERVICE),birth(BIRTH) {}
	~General() {};
};
