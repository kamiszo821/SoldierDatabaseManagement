#pragma once
#include <string>
using namespace std;
class Soldier
{
	string rank;
	string role;
	string name;
	string surname;
	int years_of_service;
	string birth;
public:

	virtual string getrank() = 0;
	virtual string getrole() = 0;
	virtual string getname() = 0;
	virtual string getsurname() = 0;
	virtual int getyears_of_service() = 0;
	virtual string getbirth() = 0;
};

