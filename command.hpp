#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include <iostream>
#include <limits>
#include "base.hpp"

template<class T>
T GetA() {
	T ret;
	while (true) {
		if (cin >> ret) break;
		std::cout << "invalid input!" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return ret;
}

void Command(Player &player, Grid &grid, std::map<Position, Grid> &mp);

template<int floor, int section>
void Goto(Player &player, Grid &grid) {
	player.pos = Position{floor, section};
}

#endif