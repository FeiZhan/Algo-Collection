// no DP

#include <iostream>
using namespace std;

#include <string>
#include <vector>

int main() {
	string str;
	while (cin >> str) {
		long long p_letter(0);
		long long a_letter(0);
		long long t_letter(0);
		//vector<long long> letter_list(str.length(), 0);
		for (size_t i = 0; i < str.length(); ++ i) {
			switch (str[i]) {
			case 'p':
			case 'P':
				++ p_letter;
				break;
			case 'a':
			case 'A':
				a_letter += p_letter;
				break;
			case 't':
			case 'T':
				t_letter += a_letter;
				break;
			}
		}
		cout << t_letter % 1000000007 << endl;
	}
	return 0;
}