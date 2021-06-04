#include <iostream>
#include <map>
#include <cassert>
#include "genmap.hpp"
#include "base.hpp"
#include "command.hpp"
#include "config.hpp"

int main() {
	std::map<Position, Grid> mp = GenMap();
	Player player{{1, 0}, 0, 0, 0};
	std::map<Position, std::string> note {
		{SUCC_POS, "success"}, {FAIL_POS, "fail"}, {QUIT_POS, "quit"}
	};
	while (true) {
		for (const auto &pr: note) if (player.pos == pr.first) {
			std::cout << pr.second << std::endl;
			break;
		}
		std::map<Position, Grid>::iterator it = mp.find(player.pos);
		assert(it != mp.end());
		// if (it == mp.end()) {
		// 	std::cout << "Internal Error, go to invalid grid (" << player.pos.floor << ", " << player.pos.section << ")" << std::endl;
		// 	break;
		// }
		Grid &gd = it->second;
		player.show_state(gd);
		if (!gd.desc.empty()) std::cout << gd.desc << std::endl;
		Command(player, gd, mp);
	}
	return 0;
}