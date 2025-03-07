#pragma once
#include "hero.h"
#include "monster.h"

class game
{
private:
	hero hero;
	monster monsters[10];
	int num_monsters;
	bool heroalive, monstersalive;

public:
	game(int);
	void initialize();
	void start();
	void run();
	void end();

	
};

