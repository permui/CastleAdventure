#ifndef __GENMAP_HPP__
#define __GENMAP_HPP__

#include <vector>
#include <map>
#include "base.hpp"

std::vector<Grid> GenGrids();

std::map<Position, Grid> GenMap();

#endif