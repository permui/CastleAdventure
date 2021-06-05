#include <iostream>
#include <map>
#include <string>
#include "base.hpp"
#include "command.hpp"

bool Position::operator<(const Position &b) const {
	return floor < b.floor || (floor == b.floor && section < b.section);
}

bool Position::operator==(const Position &b) const {
	return floor == b.floor && section == b.section;
}

Player::Player(const Position &_pos, int _shield, int _sword, int _btc) :
	pos(_pos), shield(_shield), sword(_sword), btc(_btc), with_princess(false) {}

void Player::show_state(const Grid &grid) const {
	std::cout << "You are at (floor " << pos.floor << ", section " << pos.section << ") [" << grid.name << "]" << std::endl;
	std::cout << "shield: " << shield << " | sword: " << sword << " | ";
	std::cout << "BitCoin: " << btc;
	if (with_princess) std::cout << " | with princess";
	std::cout << std::endl;
}

Info::Info(GT _t) : t(_t) {}

Grid::Grid(const Position &_pos, const Info &_info, const std::string &_name, const std::string &_desc, const std::map<std::string, Action>& _commands) :
	pos(_pos), info(_info), name(_name), desc(_desc), commands(_commands) {}
