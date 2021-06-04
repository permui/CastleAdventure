#include <iostream>
#include <map>
#include "genmap.hpp"
#include "base.hpp"

int main() {
	std::map<Position, Grid> mp = GenMap();
	Player player{{1, 0}, 0, 0, 0};
	while (true) {
		if (player.pos == Position{0, 0}) {
			std::cout << "success" << std::endl;
			break;
		}
		if (player.pos == Position{0, -1}) {
			std::cout << "fail" << std::endl;
			break;
		}
		std::map<Position, Grid>::iterator it = mp.find(player.pos);
		if (it == mp.end()) {
			std::cout << "Internal Error, go to invalid grid (" << player.pos.floor << ", " << player.pos.section << ")" << std::endl;
			break;
		}
		Grid &gd = it->second;
		gd(player);
	}
	return 0;
}