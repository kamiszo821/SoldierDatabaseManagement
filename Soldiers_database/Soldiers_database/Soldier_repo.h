#pragma once
#include <memory>;
#include <list>;
#include "Soldier.h"
 class Soldier_repo
{
	 list<shared_ptr<Soldier*>> soldier;
public:
	Soldier_repo() {};
	~Soldier_repo() {};
	void add_soldier();
	void delete_soldier();
	void display_soldier();
	void save();
	void load();
	void size();
};
