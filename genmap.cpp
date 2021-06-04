#include <vector>
#include <map>
#include <iostream>
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
			"This is the entry of the castle.",
			{
				{"quit", [](Player& player, Grid&)->void {
					player.pos = QUIT_POS;
				}},
				{"success", [](Player &player, Grid&)->void {
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
				{"buy_shield", [](Player &player, Grid&)->void {
					if (player.btc < shield_price) {
						cout << "You don't have enough money to buy it..." << endl;
					} else {
						player.btc -= shield_price;
						player.shield += 1;
					}
				}},
				{"buy_sword", [](Player &player, Grid&)->void {
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
				{"go_down", Goto<2, 7>}
			}
		},
		{
			{2, 6},
			GT::None,
			"Add Game",
			"Enter \"play\" and you will get an addition. Answer it in 5 seconds and you will get 2 BitCoins.",
			{
				{"play", games::add_game},
				{"go_down", Goto<2, 5>}
			}
		},
		{
			{2, 7},
			GT::None,
			"Mul Game",
			"Enter \"play\" and you will get a multiplication. Answer it in 5 seconds and you will get 4 BitCoins.",
			{
				{"play", games::mul_game},
				{"go_up", Goto<2, 5>}
			}
		},
		{
			{2, 8},
			GT::None,
			"Int Game",
			"Enter \"play\" and you will get an integration. Answer it in 5 seconds and you will get 6 BitCoins.",
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
		// {
		// 	{3, 10}
		// }
	};
	return ret;
}

map<Position, Grid> GenMap() {
	vector<Grid> vec = GenGrids();
	map<Position, Grid> mp;
	for (const Grid &g: vec) mp.emplace(g.pos, g);
	return mp;
}