#include "base.hpp"

Position::Position(int _floor, int _section) : floor(_floor), section(_section) {}

bool Position::operator<(const Position &b) const {
	return floor < b.floor || (floor == b.floor && section < b.section);
}

bool Position::operator==(const Position &b) const {
	return floor == b.floor && section == b.section;
}

Player::Player(const Position &_pos, int _shield, int _sword, int _btc) : pos(_pos), shield(_shield), sword(_sword), btc(_btc) {}

Info::Info(int _x) : x(_x) {}

Grid::Grid(const Position &_pos, const Info &_info, const Action& _action) : pos(_pos), info(_info), action(_action) {}

void Grid::operator()(Player &player) {
	action(player, info);
}