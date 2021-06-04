#include <iostream>
#include <map>
#include <functional>
#include <exception>
#include <string>
#include "command.hpp"
#include "base.hpp"

using std::cout, std::endl, std::string, std::map;

void Command(Player &player, Grid &grid, map<Position, Grid> &mp) {
	cout << "Commands:";
	if (grid.commands.empty()) {
		// if the design is right, this is impossible
		cout << " no commands availible" << endl;
		return;
	}
	for (const auto &pr: grid.commands) cout << ' ' << pr.first;
	cout << endl;
	map<string, Action>::iterator it;
	while (true) {
		string com = GetA<string>();
		it = grid.commands.find(com);
		if (it != grid.commands.end()) break;
		cout << "given command not available, see the command list" << endl;
	}
	it->second(player, grid);
}