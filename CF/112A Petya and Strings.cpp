//
#include <iostream>
using namespace std;

#include <algorithm>
#include <string>

int main (int argc, char *argv[])
{
	string input[2];
	while (cin >> input[0] >> input[1]) {
		for (int i = 0; i < 2; ++ i) {
			std::transform(input[i].begin(), input[i].end(), input[i].begin(), ::tolower);
		}
		cout << input[0].compare(input[1]) << endl;
	}

	return 0;
}