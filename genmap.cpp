#include <vector>
#include <map>
#include "base.hpp"
#include "genmap.hpp"
#include "config.hpp"


std::vector<Grid> GenGrids() {
	std::vector<Grid> ret = {
		{
			{1, 0},
			{0},
			[](Player &player, Info &info)->void {
				
			}
		}
	};
	return ret;
}

std::map<Position, Grid> GenMap() {
	std::vector<Grid> vec = GenGrids();
	std::map<Position, Grid> mp;
	for (const Grid &g: vec) mp.emplace(g.pos, g);
	return mp;
}