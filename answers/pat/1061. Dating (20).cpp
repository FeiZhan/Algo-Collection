//
#include <iostream>
using namespace std;

#include <string>
#include <vector>

int main (int argc, char *argv[])
{
	vector<string> WEEK;
	WEEK.push_back(string("MON"));
	WEEK.push_back(string("TUE"));
	WEEK.push_back(string("WED"));
	WEEK.push_back(string("THU"));
	WEEK.push_back(string("FRI"));
	WEEK.push_back(string("SAT"));
	WEEK.push_back(string("SUN"));
	string str[4];
	while (std::getline(std::cin, str[0])) {
		for (size_t i = 1; i < 4; ++ i) {
			// should read as line
			std::getline(std::cin, str[i]);
		}
		int count(0);
		for (size_t i = 0; i < str[0].length() && i < str[1].length(); ++ i) {
			if (str[0][i] == str[1][i]) {
				int order(-1);
				switch (count) {
				case 0:
					if (str[0][i] >= 'A' && str[0][i] <= 'G') {
						order = static_cast<int>(str[0][i] - 'A');
					}
					if (order >= 0) {
						cout << WEEK[order] << " ";
						++ count;
					}
					break;
				case 1:
					if (str[0][i] >= 'A' && str[0][i] <= 'N') {
						order = static_cast<int>(str[0][i] - 'A') + 10;
					}
					else if (str[0][i] >= '0' && str[0][i] <= '9') {
						order = static_cast<int>(str[0][i] - '0');
					}
					if (order >= 0) {
						// prepend 0
						if (order < 10) {
							cout << "0";
						}
						cout << order << ":";
						++ count;
					}
					break;
				default:
					break;
				}
				if (count > 1) {
					break;
				}
			}
		}
		for (size_t i = 0; i < str[2].length() && i < str[3].length(); ++ i) {
			if (str[2][i] == str[3][i] && ((str[2][i] >= 'a' && str[2][i] <= 'z') || (str[2][i] >= 'A' && str[2][i] <= 'Z'))) {
				if (i < 10) {
					cout << "0";
				}
				cout << i << endl;
			}
		}
	}

	return 0;
}