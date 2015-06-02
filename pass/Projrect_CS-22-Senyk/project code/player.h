#pragma once

#include <clocale>
#include <iostream>
#include <ctime>


class player
{
public:
	bool defeat_flag;
	int hits[10][10];
	int ships[10][10];

	player() : defeat_flag(0)	{}

	void ships_init();
	void set(int deck);
	int place_ship(int s, int c, direction dir, int deck);
	void turn(player&, int character, int digit);
	void turn(player&);
};