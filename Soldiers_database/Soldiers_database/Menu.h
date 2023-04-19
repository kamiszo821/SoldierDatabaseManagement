#pragma once
#include "Soldier_repo.h"
#include <iostream>
using namespace std;
class Menu
{
	string password = "baza123";
public:
	string getpassword() { return password; };
	Soldier_repo repo;
	int li;
	void Header();
	void Switch ();
	Menu();
	~Menu() {};
	static string check_data(string &birth);
};



