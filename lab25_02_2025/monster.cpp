#include "monster.h"
#include <iostream>

monster::monster()
{
	hp = 0;
	power = 0;
	level = 0;
}

monster::monster(int level)
{
	this->level = level;
	switch (level)
	{
	case 1:
		hp = 10;
		power = 2;
		break;
	case 2:
		hp = 20;
		power = 5;
		break;
	case 3:
		hp = 30;
		power = 10;
		break;
	default:
		hp = 10;
		power = 2;
		break;
	}
}

int monster::getdamage()
{
	double percentage = (rand() % 1000) / 1000.0;
	int damage = (int)(power * percentage);
	return damage;
}

void monster::defend(int damage)
{
	hp -= damage;
}

bool monster::isalive()
{
	return hp > 0;
}