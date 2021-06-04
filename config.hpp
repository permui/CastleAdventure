#ifndef __CONFIG_HPP__
#define __CONFIG_HPP__

#include "base.hpp"

const double monster_probability = 3. / 5;

constexpr Position QUIT_POS{0, 1};
constexpr Position SUCC_POS{0, 0};
constexpr Position FAIL_POS{0, -1};

const int shield_price = 10;
const int sword_price = 15;

const int add_award = 2;
const int mul_award = 4;
const int int_award = 6;

#endif