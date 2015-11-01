//
#include <iostream>
using namespace std;

#include <cmath>

int main (int argc, char *argv[])
{
	long long number(0);
	while (cin >> number) {
		long long sqrt2 = sqrt(number);
		cout << number << "=";
		for (long long i = 2; i < sqrt2 && i < number; ++ i) {
			int count(0);
			while (0 == number % i) {
				++ count;
				number /= i;
			}
			if (count > 0) {
				cout << i;
				if (count > 1) {
					cout << "^" << count;
				}
				if (number > 1) {
					cout << "*";
				}
			}
		}
		if (number > 1 || 1 == sqrt2) {
			cout << number;
		}
		cout << endl;
	}

	return 0;
}