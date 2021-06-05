#include <iostream>
#include <map>
#include <functional>
#include <exception>
#include <string>
#include "command.hpp"
#include "base.hpp"
#include "config.hpp"

using std::cout, std::endl, std::string, std::map;

void Command(Player &player, Grid &grid, map<Position, Grid> &mp) {
	switch (grid.info.t) {
		case GT::Monster: {
			EncounterMonster(player, grid);
			if (player.pos == FAIL_POS || player.pos == QUIT_POS) return;
			break;
		}
		case GT::Princess: {
			EncounterPrincess(player, grid);
			break;
		}
		default:
			break;
	}
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
	it->second(player, grid, mp);
}

void EncounterMonster(Player &player, Grid &grid) {
	cout << "Encounter Monster!" << endl;
	cout << "A shield (" << shield_price << " BTC) can defend against one time of monster attact, but cannot kill the monster." << endl;
	cout << "A sword (" << sword_price << " BTC) can kill the monster." << endl;
	cout << "Commands: use_shield use_sword give_up" << endl;
	while (true) {
		string com = GetA<string>();
		if (com == "use_shield") {
			if (player.shield > 0) {
				--player.shield;
				cout << "You defend the monster!" << endl;
				break;
			}
			cout << "not enough shield, choose an alternative" << endl;
		} else if (com == "use_sword") {
			if (player.sword > 0) {
				--player.sword;
				grid.info.t = GT::None;
				cout << "You kill the monster!" << endl;
				break;
			}
			cout << "not enogh sword, choose an alternative" << endl;
		} else if (com == "give_up") {
			player.pos = FAIL_POS;
			break;
		} else {
			cout << "given command not available, see the command list" << endl;
		}
	}
}

void EncounterPrincess(Player &player, Grid &grid) {
	cout << "Lovely Princess Here!" << endl;
	cout << "Commands: pick_her leave_her_alone" << endl;
	while (true) {
		string com = GetA<string>();
		if (com == "pick_her") {
			grid.info.t = GT::None;
			player.with_princess = true;
			break;
		} else if (com == "leave_her_alone") {
			break;
		}
	}
}