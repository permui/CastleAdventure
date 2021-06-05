#include <vector>
#include <map>
#include <iostream>
#include <random>
#include <cassert>
#include "base.hpp"
#include "genmap.hpp"
#include "config.hpp"
#include "command.hpp"
#include "games.hpp"

using namespace std;

vector<Grid> GenGrids() {
	vector<Grid> ret = {
		{
			{1, 0},
			GT::None,
			"entry",
			("This is the entry of the castle.\n"
			"If you want to quit, just type \"quit\".\n"
			"If you think you have successfully rescued the princess, claim \"success\".\n"
			"Or just go_left to enter the castle."),
			{
				{"quit", [](Player& player, Grid&, Map&)->void {
					player.pos = QUIT_POS;
				}},
				{"success", [](Player &player, Grid&, Map&)->void {
					if (player.with_princess) {
						cout << "Rescue princess successful!" << endl;
						player.pos = SUCC_POS;
					} else {
						cout << "You don't have princess with you???" << endl;
					}
				}},
				{"go_left", Goto<1, 1>}
			}
		},
		{
			{1, 1},
			GT::None,
			"living room",
			"",
			{
				{"go_right", Goto<1, 0>},
				{"go_left", Goto<1, 3>},
				{"go_up", Goto<1, 2>}
			}
		},
		{
			{1, 2},
			GT::None,
			"shop",
			("Why there is a shop in a castle?!\n" "You can buy the following with BitCoin:\n" 
			"a shield that can defend against one time of monster attact: 10 BTC\n"
			"a sword that can kill a monster: 15 BTC\n"),
			{
				{"buy_shield", [](Player &player, Grid&, Map&)->void {
					if (player.btc < shield_price) {
						cout << "You don't have enough money to buy it..." << endl;
					} else {
						player.btc -= shield_price;
						player.shield += 1;
					}
				}},
				{"buy_sword", [](Player &player, Grid&, Map&)->void {
					if (player.btc < sword_price) {
						cout << "You don't have enough money to buy it..." << endl;
					} else {
						player.btc -= sword_price;
						player.sword += 1;
					}
				}},
				{"go_down", Goto<1, 1>}
			}
		},
		{
			{1, 3},
			GT::None,
			"lift",
			"You are on the lift, this is floor 1",
			{
				{"go_floor_2", Goto<2, 4>},
				{"go_floor_3", Goto<3, 9>},
				{"go_right", Goto<1, 1>}
			}
		},
		{
			{2, 4},
			GT::None,
			"lift",
			"You are on the lift, this is floor 2",
			{
				{"go_floor_1", Goto<1, 3>},
				{"go_floor_3", Goto<3, 9>},
				{"go_right", Goto<2, 5>}
			}
		},
		{
			{2, 5},
			GT::None,
			"playing center",
			("This is the playing center. There are three games in up / right / down directions.\n"
			"You can earn coins from them."),
			{
				{"go_up", Goto<2, 6>},
				{"go_right", Goto<2, 8>},
				{"go_down", Goto<2, 7>},
				{"go_left", Goto<2, 4>}
			}
		},
		{
			{2, 6},
			GT::None,
			"Add Game",
			"Enter \"play\" and you will get an addition. Answer it in 7 seconds and you will get 2 BitCoins.",
			{
				{"play", games::add_game},
				{"go_down", Goto<2, 5>}
			}
		},
		{
			{2, 7},
			GT::None,
			"Mul Game",
			"Enter \"play\" and you will get a multiplication. Answer it in 10 seconds and you will get 4 BitCoins.",
			{
				{"play", games::mul_game},
				{"go_up", Goto<2, 5>}
			}
		},
		{
			{2, 8},
			GT::None,
			"Int Game",
			"Enter \"play\" and you will get an integration. Answer it in 15 seconds and you will get 6 BitCoins.",
			{
				{"play", games::int_game},
				{"go_left", Goto<2, 5>}
			}
		},
		{
			{3, 9},
			GT::None,
			"lift",
			"You are on the lift, this is floor 3",
			{
				{"go_floor_1", Goto<1, 3>},
				{"go_floor_2", Goto<2, 4>},
				{"go_right", Goto<3, 10>}
			}
		},
		{
			{3, 10},
			GT::None,
			"CorridorEntry",
			"On your right is a corridor, with many monsters in it. Go ahead, warrior!",
			{
				{"go_left", Goto<3, 9>},
				{"go_right", Goto<3, 11>}
			}
		},
		{
			{3, 11},
			GT::MayHaveMonster,
			"Corridor Step 1",
			"",
			{
				{"go_left", Goto<3, 10>},
				{"go_right", Goto<3, 12>}
			}
		},
		{
			{3, 12},
			GT::MayHaveMonster,
			"Corridor Step 2",
			"",
			{
				{"go_left", Goto<3, 11>},
				{"go_right", Goto<3, 13>}
			}
		},
		{
			{3, 13},
			GT::MayHaveMonster,
			"Corridor Step 3",
			"",
			{
				{"go_left", Goto<3, 12>},
				{"go_right", Goto<3, 14>}
			}
		},
		{
			{3, 14},
			GT::MayHaveMonster,
			"Corridor Step 4",
			"",
			{
				{"go_left", Goto<3, 13>},
				{"go_right", Goto<3, 15>}
			}
		},
		{
			{3, 15},
			GT::MayHaveMonster,
			"Corridor Step 5",
			"",
			{
				{"go_left", Goto<3, 14>},
				{"go_right", Goto<3, 16>}
			}
		},
		{
			{3, 16},
			GT::Princess,
			"Princess' Place",
			"",
			{
				{"go_left", Goto<3, 15>},
				{"go_right", Goto<3, 17>}	
			}
		},
		{
			{3, 17},
			GT::None,
			"Teleporter",
			"Give me 20 BitCoins and you will be transported to a random place in the castle!",
			{
				{"go_left", Goto<3, 16>},
				{"teleport", [](Player &player, Grid&, Map &mp)->void {
					if (player.btc < tele_price) {
						cout << "You don't have " << tele_price << " BitCoins. Work hard, man!" << endl;
						return;
					}
					player.btc -= tele_price;
					assert(!mp.empty());
					default_random_engine eng((random_device())());
					uniform_int_distribution<int> dis(0, (int)mp.size() - 1);
					int num = dis(eng);
					Map::iterator it = mp.begin();
					while (num--) ++it;
					player.pos = it->first;
				}}
			}
		}
	};
	default_random_engine eng((random_device())());
	uniform_real_distribution<double> dis(0, 1);
	for (Grid &grid: ret) if (grid.info.t == GT::MayHaveMonster) {
		grid.info.t = dis(eng) < monster_probability ? GT::Monster : GT::None;
	}
	return ret;
}

map<Position, Grid> GenMap() {
	vector<Grid> vec = GenGrids();
	map<Position, Grid> mp;
	for (const Grid &g: vec) mp.emplace(g.pos, g);
	return mp;
}