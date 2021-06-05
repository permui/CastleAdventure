#ifndef __CONFIG_HPP__
#define __CONFIG_HPP__

#include "base.hpp"
#include <utility>

const double monster_probability = 3. / 5;

constexpr Position QUIT_POS{0, 1};
constexpr Position SUCC_POS{0, 0};
constexpr Position FAIL_POS{0, -1};

const int shield_price = 10;
const int sword_price = 15;

const int add_award = 2;
const int mul_award = 4;
const int int_award = 6;

const int add_time = 7;
const int mul_time = 10;
const int int_time = 15;

constexpr std::pair<int, int> add_range{0, 99};
constexpr std::pair<int, int> mul_range{1, 19};
constexpr std::pair<int, int> int_param{4, 4};
const int int_upper_limit_max = 4;

const int tele_price = 20;

#endif