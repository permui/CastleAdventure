#include <random>
#include <iostream>
#include <iomanip>
#include "base.hpp"
#include "games.hpp"
#include "command.hpp"
#include "config.hpp"

using namespace std;

namespace games {
	
	void add_game(Player &player, Grid&, Map&) {
		random_device r;
		default_random_engine eng(r());
		uniform_int_distribution<int> dis(add_range.first, add_range.second);
		int x = dis(eng), y = dis(eng), z = x + y;
		cout << "Answer the following question in " << add_time << " seconds" << endl;
		cout << x << " + " << y << " = ";
		pair<int, double> get = GetAin<int>();
		if (get.second > add_time) {
			cout << "Out of time! You took " << fixed << setprecision(2) << get.second << " seconds!" << endl;
			return;
		}
		if (get.first != z) {
			cout << "Wrong Answer!" << endl;
			return;
		}
		cout << "Right answer! " << add_award << " BTC to your pocket." << endl;
		player.btc += add_award;
	}

	void mul_game(Player &player, Grid&, Map&) {
		random_device r;
		default_random_engine eng(r());
		uniform_int_distribution<int> dis(mul_range.first, mul_range.second);
		int x = dis(eng), y = dis(eng), z = x * y;
		cout << "Answer the following question in " << mul_time << " seconds" << endl;
		cout << x << " * " << y << " = ";
		pair<int, double> get = GetAin<int>();
		if (get.second > mul_time) {
			cout << "Out of time! You took " << fixed << setprecision(2) << get.second << " seconds!" << endl;
			return;
		}
		if (get.first != z) {
			cout << "Wrong Answer!" << endl;
			return;
		}
		cout << "Right answer! " << mul_award << " BTC to your pocket." << endl;
		player.btc += mul_award;
	}

	void int_game(Player &player, Grid&, Map&) {
		random_device r;
		default_random_engine eng(r());
		uniform_int_distribution<int> coef(1, int_param.first);
		uniform_int_distribution<int> expo(1, int_param.second);
		uniform_int_distribution<int> uppe(1, int_upper_limit_max);
		int c = coef(eng), e = expo(eng), u = uppe(eng);
		double ans = pow(u, e + 1) * c / (e + 1);
		cout << "Answer the following question **accurate to at least 1 decimal place** in " << int_time << " seconds" << endl;
		cout << "integrate ";
		if (c > 1) cout << c << " ";
		cout << 'x';
		if (e > 1) cout << '^' << e;
		cout << " from " << 0 << " to " << u << " = ";
		pair<double, double> get = GetAin<double>();
		if (get.second > int_time) {
			cout << "Out of time! You took " << fixed << setprecision(2) << get.second << " seconds!" << endl;
			return;	
		}
		if (fabs(get.first - ans) >= 0.1) {
			cout << "Wrong Answer!" << endl;
			return;
		}
		cout << "Right answer! " << int_award << " BTC to your pocket." << endl;
		player.btc += int_award;
	}

}