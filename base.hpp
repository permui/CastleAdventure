#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <functional>

struct Position {
	int floor, section;
	Position(int _floor, int _section);
	bool operator<(const Position &b) const;
};

struct Player {
	Position pos;
	int shield, sword;
	int btc;
	Player(const Position &_pos, int _shield, int _sword, int _btc);
};

struct Info {
	int x;
	Info(int _x);
};

typedef std::function<void(Player&, Info&)> Action;

struct Grid {
	Position pos;
	Info info;
	Action action;
	Grid(const Position &_pos, const Info &_info, const Action& _action);
	void Grid::operator()(Player &player);
};

#endif