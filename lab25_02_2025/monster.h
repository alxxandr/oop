#pragma once
class monster
{
private:
	int hp;
	int power;
	int level;

public:
	monster();
	monster(int);
	int getdamage();
	void defend(int);
	bool isalive();
};

