#include <iostream>
using namespace std;

#include <string>

const string NUMBERS[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
// no 'Ge'
const string DIGITS[4] = {"","Shi","Bai","Qian"};
const string SEGMENTS[4] = {"","Wan","Yi"};
string getChinese(string number) {
	string chinese;
	bool zero_flag(false);
	while (number.length() > 0 && '0' == number[0]) {
		zero_flag = true;
		number.erase(0, 1);
	}
	if (zero_flag && number.length()) {
		chinese += "ling ";
	}
	size_t pos(number.length() - 1);
	while (pos < number.length() && '0' == number[pos]) {
		number[pos] = '*';
		-- pos;
	}
	bool prev_zero_flag(false);
	for (size_t i = 0; i < number.length(); ++ i) {
		if ('0' == number[i] && ! prev_zero_flag) {
			chinese += NUMBERS[static_cast<size_t>(number[i] - '0')] + string(" ");
		}
		else if (number[i] != '*') {
			chinese += NUMBERS[static_cast<size_t>(number[i] - '0')] + string(" ") + DIGITS[number.length() - i - 1] + string(" ");
		}
		prev_zero_flag = '0' == number[i];
	}
	while (chinese.length() > 0 && ' ' == chinese[chinese.length() - 1]) {
		chinese.erase(chinese.length() - 1, 1);
	}
	return chinese;
}
int main() {
	string number;
	while (cin >> number) {
		string chinese;
		if ('-' == number[0]) {
			chinese = "Fu ";
			number.erase(0, 1);
		}
		for (int i = 8; i >= 0; i -= 4) {
			if (number.length() > i) {
				string c = getChinese(number.substr(0, number.length() - i));
				if (c.length() > 0) {
					chinese += c + string(" ") + SEGMENTS[i / 4] + string(" ");
				}
				number.erase(0, number.length() - i);
			}
		}
		while (chinese.length() > 0 && ' ' == chinese[chinese.length() - 1]) {
			chinese.erase(chinese.length() - 1, 1);
		}
		if (0 == chinese.length()) {
			chinese = string("ling");
		}
		cout << chinese << endl;
	}
	return 0;
}