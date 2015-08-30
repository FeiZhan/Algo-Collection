//
#include <cstdio>
#include <iostream>
using namespace std;

#include <cstdlib>
#include <string>

int main (int argc, char *argv[]) {
	string scien;
	while (cin >> scien) {
		size_t found = scien.find('e');
		if (found == string::npos) {
			found = scien.find('E');
		}
		string fractional = scien.substr(0, found);
		int exponent = atoi(scien.substr(found + 1).c_str());
		size_t dot = fractional.find('.');
		if (string::npos == dot) {
			dot = fractional.length();
		}
		//cout << fractional << " e " << exponent << endl;
		if (exponent > 0) {
			int zeros = exponent - fractional.length() + dot + 1;
			if (zeros > 0) {
				fractional += string(zeros, '0');
			}
			if (fractional.size() > dot && '.' == fractional[dot]) {
				fractional.erase(dot, 1);
			}
			if (fractional.size() > dot + exponent) {
				fractional.insert(dot + exponent, 1, '.');
			}
		}
		else {
			int zeros = - exponent - dot + 2;
			if (zeros > 0) {
				fractional.insert(1, zeros, '0');
			}
			if (fractional.size() > dot + zeros + 1 && '.' == fractional[dot + zeros]) {
				fractional.erase(dot + zeros, 1);
			}
			fractional.insert(dot + zeros + exponent, 1, '.');
		}
		if ('+' == fractional[0]) {
			fractional.erase(0, 1);
		}
		cout << fractional << endl;
	}

	return 0;
}