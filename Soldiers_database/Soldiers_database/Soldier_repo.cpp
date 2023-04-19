#include <iostream>
#include "Soldier_repo.h"
#include "General.h"
#include "Pulkownik.h"
#include "Porucznik.h"
#include "Sierzant.h"
#include "Szeregowy.h"
#include <algorithm>
#include <ranges>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include <regex>
#include <filesystem>
using namespace std;

void Soldier_repo::add_soldier()
{
	cout << "Jakiego zolnierza chcesz dodac?" << endl << endl << "1.General" << endl << "2.Pulkownik" << endl << "3.Porucznik" << endl << "4.Sierzant" << endl << "5.Szeregowy" << endl;
	int wybor;
	cin >> wybor;
	system("cls");
	if (wybor == 1)
	{
 		shared_ptr<Soldier*> general = make_shared<Soldier*>(new General());
		soldier.emplace_back(general);
	}
	else if (wybor == 2)
	{
		shared_ptr<Soldier*> pulkownik = make_shared<Soldier*>(new Pulkownik());
		soldier.emplace_back(pulkownik);
	}
	else if (wybor == 3)
	{
		shared_ptr<Soldier*> porucznik = make_shared<Soldier*>(new Porucznik());
		soldier.emplace_back(porucznik);
	}
	else if (wybor == 4)
	{
		shared_ptr<Soldier*> sierzant = make_shared<Soldier*>(new Sierzant());
		soldier.emplace_back(sierzant);
	}
	else if (wybor == 5)
	{
		shared_ptr<Soldier*> szeregowy = make_shared<Soldier*>(new Szeregowy());
		soldier.emplace_back(szeregowy);
	}
}

	void Soldier_repo::display_soldier()
	{ 
		int id_counter = 0;
		for (auto const& i : soldier) {
			cout << "ID: " << id_counter << "   ";
			cout << "Rola: ";
			std::cout << (*i)->getrank() << "   ";
			cout << "Imie: ";
			std::cout << (*i)->getname() << "   ";
			cout << "Nazwisko: ";
			std::cout << (*i)->getsurname() << "   ";
			cout << "Lata sluzby: ";
			std::cout << (*i)->getyears_of_service() << "   ";
			cout << "Data urodzenia: ";
			std::cout << (*i)->getbirth() << endl;
			id_counter++;
		}
		cout << endl << endl;
	}


void Soldier_repo::delete_soldier()
{

	if (soldier.empty())
		cout << "Baza zolnierzy jest pusta" << endl;
		else
		{
			int delete_el;
			cout << "Podaj ID zolnierza ktorego chcesz usunac" << endl;
			display_soldier();
			cin >> delete_el;
			list<shared_ptr<Soldier*>>::iterator it = soldier.begin();
			advance(it, delete_el);
			soldier.erase(it);
		}
		system("cls");
}

void Soldier_repo::save()
{
	ofstream plik;
	plik.open("Baza.txt");
	for (auto const& i : soldier)
	{
		plik << (*i)->getrank() << " ";
		plik << (*i)->getrole() << " ";
		plik << (*i)->getname() << " ";
		plik << (*i)->getsurname() << " ";
		plik << (*i)->getyears_of_service() << " ";
		plik << (*i)->getbirth() << " " << endl;
	}
	plik.close();

	cout << "Baze zapisano w: " << endl;
	const filesystem::path current{ filesystem::current_path() };
		int j = 0;
		for (const auto& part : current)
			cout << part;
		cout << endl;
}


void Soldier_repo::load()
{
	soldier.clear();
	string rank,role,name,surname,birth;
	int years_of_service;
	ifstream plik("Baza.txt");
	while (plik >> rank >> role >> name >> surname>>years_of_service>>birth)
	{
		if (rank == "General")
		{
			shared_ptr<Soldier*> general = make_shared<Soldier*>(new General(rank, role, name,surname,years_of_service,birth));
			soldier.emplace_back(general);

		}
		if (rank == "Pulkownik")
		{
			shared_ptr<Soldier*> pulkownik = make_shared<Soldier*>(new Pulkownik(rank, role, name, surname, years_of_service,birth));
			soldier.emplace_back(pulkownik);
		}
		if (rank == "Porucznik")
		{
			shared_ptr<Soldier*> porucznik = make_shared<Soldier*>(new Porucznik(rank, role, name, surname, years_of_service,birth));
			soldier.emplace_back(porucznik);
		}
		if (rank == "Sierzant")
		{
			shared_ptr<Soldier*> sierzant = make_shared<Soldier*>(new Sierzant(rank, role, name, surname, years_of_service,birth));
			soldier.emplace_back(sierzant);
		}
		if (rank == "Szeregowy")
		{
			shared_ptr<Soldier*> szeregowy = make_shared<Soldier*>(new Szeregowy(rank, role, name, surname, years_of_service,birth));
			soldier.emplace_back(szeregowy);
		}
	}
	plik.close();
}



void Soldier_repo::size()
{
	if (!soldier.empty())
	{
		cout << "size = " << filesystem::file_size("Baza.txt") << '\n';
		cout << "Jest"<<' '<< std::ranges::size(soldier) <<' '<< "zolnierzy" << endl;
	}
	else 
		cout << "0" << endl;
}

