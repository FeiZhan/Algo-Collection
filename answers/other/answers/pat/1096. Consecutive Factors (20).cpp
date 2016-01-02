#include <iostream>
using namespace std;

int main() {
	long long number(0);
	while (cin >> number) {
		long long count(0);
		long long start(0);
		for (long long i = 2; i * i <= number; ++ i) {
			long long temp(number);
			long long j(i);
			for (; j <= temp && temp % j == 0; ++ j) {
				temp /= j;
			}
			if (j - i > count) {
				count = j - i;
				start = i;
			}
		}
		if (count > 0) {
			cout << count << endl << start;
			for (long long i = start + 1; i < start + count; ++ i) {
				cout << "*" << i;
			}
			cout << endl;
		}
		// don't know why
		else {
			cout << 1 << endl << number << endl;
		}
	}
	return 0;
}