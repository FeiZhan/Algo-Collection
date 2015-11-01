//
#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

int main (int argc, char *argv[])
{
	string input;
	cin >> input;
	long long num(0);
	for (size_t i = 0; i < input.length(); ++ i) {
		num += static_cast<int> (input[i] - '0');
	}
	vector<string> chinese;
	chinese.push_back(string("ling"));
	chinese.push_back(string("yi"));
	chinese.push_back(string("er"));
	chinese.push_back(string("san"));
	chinese.push_back(string("si"));
	chinese.push_back(string("wu"));
	chinese.push_back(string("liu"));
	chinese.push_back(string("qi"));
	chinese.push_back(string("ba"));
	chinese.push_back(string("jiu"));
	vector<string> output;
	while (num > 0) {
		output.push_back(chinese[num % 10]);
		num /= 10;
	}
	string output_all;
	for (vector<string>::reverse_iterator it = output.rbegin(); it != output.rend(); ++ it) {
		output_all += *it + string(" ");
	}
	if (output_all.length() > 0) {
		output_all = output_all.substr(0, output_all.length() - 1);
	}
	cout << output_all << endl;

	return 0;
}
