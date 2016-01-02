//@type simple, greedy
//@result 12779644	2015-08-30 20:01:18	zetta217	556A - Case of the Zeros and Ones	GNU C++	Accepted	873 ms	500 KB
#include <cstdio>
#include <iostream>
using namespace std;

#include <string>

int main (int argc, char *argv[]) {
	int length(0);
	while (cin >> length) {
		string str;
		cin >> str;
		for (int i = 1; i < str.length(); ++ i) {
			if (str[i - 1] != str[i]) {
				str.erase(i - 1, 2);
				i -= 2;
			}
			if (i < 0) {
				i = 0;
			}
		}
		cout << str.length() << endl;
	}

	return 0;
}