//
#include <cstdio>
#include <iostream>
using namespace std;

#include <string>

int main (int argc, char *argv[]) {
	int digits(0);
	while (cin >> digits) {
		string num[2];
		int dot[2];
		for (size_t i = 0; i < 2; ++ i) {
			cin >> num[i];
			while (num[i].length() > 0 && '0' == num[i][0]) {
				num[i].erase(0, 1);
			}
			dot[i] = num[i].find('.');
			if (string::npos == dot[i]) {
				dot[i] = num[i].length();
			}
			else {
				num[i].erase(dot[i], 1);
				while (num[i].length() > 0 && '0' == num[i][0]) {
					num[i].erase(0, 1);
					-- dot[i];
				}
			}
			if (0 == num[i].length()) {
				//num[i] = string("0.0");
				dot[i] = 0;
			}
			if (num[i].length() >= digits) {
				num[i] = string("0.") + num[i].substr(0, digits);
			}
			else {
				num[i] = string("0.") + num[i] + string(digits - num[i].length(), '0');
			}
		}
		if (num[0] == num[1] && dot[0] == dot[1]) {
			cout << "YES " << num[0] << "*10^" << dot[0] << endl;
		}
		else {
			cout << "NO " << num[0] << "*10^" << dot[0] << " " << num[1] << "*10^" << dot[1] << endl;
		}
	}

	return 0;
}