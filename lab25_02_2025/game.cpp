#include "game.h"
#include <iostream>
using namespace std;

game::game(int noMonsters)
{
	num_monsters = noMonsters;
}

void game::initialize()
{
	//initializare erou 
	int hp, power, defense;
	char nume[100];

	cout << " Introduceti numele eroului: ";
	cin >> nume;
	cout << " Introduceti atributele eroului (hp, power, defense): ";
	cin >> hp >> power >> defense;
	hero = hero::hero(hp, power, defense, nume); // sau alt nume pt hero ca sa nu fie confuizei

	int lvl;
	for (int i = 0; i < num_monsters; i++)
	{
		cout << "Nivelul monstrului " << i + 1 << ": ";
		cin >> lvl;
		monsters[i] = monster(lvl);

	}
}

void game::start()
{
	heroalive = true;
	monstersalive = true;

	while (heroalive && monstersalive)
	{
		run();
	}
}

void game::run()
{
	/*monstersalive = false;
	for (int i = 0; i < num_monsters; i++)
	{
		if (monsters[i].isalive())
		{
			monstersalive = true;
			int dmg = monsters[i].getdamage();
			cout << "Monstrul " << i + 1 << " ataca eroul " << hero.getname() << " cu " << dmg << "." << endl;
			hero.defend(dmg);

			if (hero.isalive())
			{
				cout << "Eroul " << hero.getname() << " a ramas in viata!" << endl;
				hero.attackmonster(monsters[i]);
				cout << hero.getname() << " ataca monstrul " << i + 1 << endl;
				if (monsters[i].isalive())
				{
					cout << "Monstrul " << i + 1 << " a ramas in viata!" << endl;
				}
				else
				{
					cout << "Monstrul " << i + 1 << " a murit!" << endl;
				}
			}
			else
			{
				cout << "Eroul " << hero.getname() << " a murit!" << endl;
				heroalive = false;

			}
		}
	}*/

	monstersalive = false;
	for (int i = 0; i < num_monsters; i++)
	{
		if (monsters[i].isalive())
		{
			monstersalive = true;
			do
			{
				int dmg = monsters[i].getdamage();
				cout << "Monstrul " << i + 1 << " ataca eroul " << hero.getname() << " cu " << dmg << "." << endl;
				hero.defend(dmg);

				if (hero.isalive())
				{
					cout << "Eroul " << hero.getname() << " a ramas in viata!" << endl;
					hero.attackmonster(monsters[i]);
					cout << hero.getname() << " ataca monstrul " << i + 1 << endl;
					if (monsters[i].isalive())
					{
						cout << "Monstrul " << i + 1 << " a ramas in viata!" << endl;
					}
					else
					{
						cout << "Monstrul " << i + 1 << " a murit!" << endl;
					}
				}
				else
				{
					cout << "Eroul " << hero.getname() << " a murit!" << endl;
					heroalive = false;

				}


			} while (monsters[i].isalive() && hero.isalive());
		}
	}
}
void game::end()
{
	if (monstersalive)
	{
		cout << "Monstrii au castigat!" << endl;
	}
	else
	{
		cout << "Eroul " << hero.getname() << " a castigat!" << endl;
	}
}