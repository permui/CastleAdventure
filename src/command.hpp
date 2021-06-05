#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include <iostream>
#include <limits>
#include <chrono>
#include "base.hpp"

template<class T>
T GetA() {
	T ret;
	while (true) {
		if (std::cin >> ret) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
		std::cout << "invalid input!" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return ret;
}

template<class T>
std::pair<T, double> GetAin() {
	auto t1 = std::chrono::high_resolution_clock::now();
	T ret = GetA<T>();
	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> sec = t2 - t1;
	return {ret, sec.count()};
}

void Command(Player &player, Grid &grid, std::map<Position, Grid> &mp);

template<int floor, int section>
void Goto(Player &player, Grid &grid, Map&) {
	player.pos = Position{floor, section};
}

void EncounterMonster(Player &player, Grid &grid);

void EncounterPrincess(Player &player, Grid &grid);

#endif