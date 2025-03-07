#pragma once
#include "monster.h"

class hero
{
private:
	int hp;
	int power;
	int defense;
	char* name;

public:
	hero();
	hero(int, int, int, char*);
	void attackmonster(monster&);
	void defend(int);
	char* getname();
	bool isalive();
};

