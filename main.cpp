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
		bool go_out = false;
		for (const auto &pr: note) if (player.pos == pr.first) {
			std::cout << pr.second << std::endl;
			go_out = true;
			break;
		}
		if (go_out) break;
		std::map<Position, Grid>::iterator it = mp.find(player.pos);
		assert(it != mp.end());
		Grid &gd = it->second;
		player.show_state(gd);
		if (!gd.desc.empty()) std::cout << gd.desc << std::endl;
		Command(player, gd, mp);
	}
	return 0;
}