#pragma warning(disable:4996)
#include "hero.h"
#include <iostream>

hero::hero()
{
	hp = 0;
	power = 0;
	defense = 0;
	name = nullptr;
}
hero::hero(int hp, int power, int defense, char* name)
{
	this->hp = hp;
	this->power = power;
	this->defense = defense;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void hero::attackmonster(monster& m)
{
	double percentage = (rand() % 1000) / 1000.0;
	int damage = (int)(power * percentage);
	m.defend(damage);

}

void hero::defend(int damage)
{
	int final_damage = 0;
	if (damage - defense > 0)
		final_damage = damage - defense;

	defense--;
	hp -= final_damage;
}

char* hero::getname()
{
	return name;
}

bool hero::isalive()
{
	return hp > 0;
}