//@type simple, greedy, implementation, two pointers
//@result 12779886	2015-08-30 20:23:35	zetta217	416A - Guess a number!	GNU C++	Accepted	61 ms	0 KB
#include <iostream>
using namespace std;

#include <climits>
#include <string>

int main() {
	int quest_num(0);
	while (cin >> quest_num) {
		int max(2e9);
		int min(-2e9);
		for (int i = 0; i < quest_num; ++ i) {
			string inequation;
			int number(0);
			char answer('\0');
			cin >> inequation >> number >> answer;
			if ('N' == answer) {
				if (string(">=") == inequation) {
					inequation = string("<");
				}
				else if (string("<=") == inequation) {
					inequation = string(">");
				}
				else if (string(">") == inequation) {
					inequation = string("<=");
				}
				else if (string("<") == inequation) {
					inequation = string(">=");
				}
			}
			if (string(">") == inequation) {
				inequation = string(">=");
				++ number;
			}
			else if (string("<") == inequation) {
				inequation = string("<=");
				-- number;
			}
			if (string(">=") == inequation && number > min) {
				min = number;
			}
			else if (string("<=") == inequation && number < max) {
				max = number;
			}
		}
		if (min > max) {
			cout << "Impossible" << endl;
		}
		else {
			// cannot set to (min + max) / 2
			cout << min << endl;
		}
	}
	return 0;
}