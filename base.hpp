#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <functional>
#include <string>
#include <map>

enum class GT { Princess, Monster, MayHaveMonster, None };

struct Position {
	int floor, section;
	constexpr Position(int _floor, int _section) : floor(_floor), section(_section) {}
	bool operator<(const Position &b) const;
	bool operator==(const Position &b) const;
};

struct Player {
	Position pos;
	int shield, sword;
	int btc;
	bool with_princess;
	Player(const Position &_pos, int _shield, int _sword, int _btc);
	void show_state(const Grid &grid) const;
};

struct Info {
	GT t;
	Info(GT _t);
};

struct Grid;

typedef std::function<void(Player&, Grid&)> Action;

struct Grid {
	Position pos;
	Info info;
	std::string name;
	std::string desc;
	std::map<std::string, Action> commands;

	Grid(const Position &_pos, const Info &_info, const std::string &_name, const std::string &desc, const std::map<std::string, Action>& _commands);
	// void Grid::operator()(Player &player);
};

#endif