//
#include <iostream>
using namespace std;



int main (int argc, char *argv[])
{
	int num(0);
	while (cin >> num) {
		int base(1);
		int count(0);
		while (num / base) {
			int right = num % base;
			int left = num / (base * 10);
			int current = (num / base) % 10;
			if (0 == current) {
				count += left * base;
			}
			else if (1 == current) {
				count += left * base + right + 1;
			}
			else {
				count += (left + 1) * base;
			}
			base *= 10;
		}
		cout << count << endl;
	}

	return 0;
}