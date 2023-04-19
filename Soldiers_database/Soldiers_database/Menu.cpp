#include "Menu.h"

#include <regex>;
#include <chrono>;
#include <thread>;

#include "Soldier.h"
#include "Porucznik.h"

Menu::Menu()
{
	string temp_password;
	string mail;
	while (true) {
		cout << "Podaj poprawne haslo" << endl;
		getline(cin, temp_password);

		if (temp_password == getpassword()) {
			break;
		}
		system("cls");
	}
}

string Menu::check_data(string& birth)
{
	while (!(regex_match(birth, regex("[0-3][0-9].[0-1][0-9].[0-9][0-9][0-9][0-9]"))))
	{
		cout<<"Nienoprawny format daty! Podaj poprawnie date (DD.MM.RRRR)"<<endl;
		cin >> birth;
		this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	return birth;
}



void Menu::Header()
{
	cout << "-----------------------" << endl;
	cout << "BAZA ZOLNIERZY" << endl;
	cout << "-----------------------" << endl << endl << endl;
}

void Menu::Switch()
{
	do
	{
		cout << "1.DODAJ " << endl << "2.USUN" << endl << "3.WYSWIETL" << endl << "4.ZAPISZ" << endl << "5.LADUJ" << endl << "6.ROZMIAR BAZY" <<endl<<"7.ZAKONCZ PROGRAM"<< endl << endl;
		cin >> li;
		system("cls");
		switch (li)
		{
		case 1:
			repo.add_soldier();
			break;
		case 2:
			repo.delete_soldier();
			break;
		case 3:
			repo.display_soldier();
			break;
		case 4:
			repo.save();
			break;
		case 5:
			repo.load();
			break;
		case 6:
			repo.size();
			break;
		}
	} while (li != 7); 
}



