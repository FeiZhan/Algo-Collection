//
#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
using namespace std;

#include <map>

int main(int argc, char *argv[])
{
#ifdef _FILE_DEBUG_
	ifstream fin;
	fin.open("input.txt");
	cin.rdbuf(fin.rdbuf());
#ifdef _C_LAN_
	freopen("input.txt", "r", stdin);
#endif
#endif
#ifdef _FILE_DEBUG_
	ofstream fout;
	fout.open("output.txt");
	cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("output.txt", "w", stdout);
#endif
#endif

	typedef long long Number;
	Number num0(0), num1(0);
	map<Number, Number> num_map;
	while (cin >> num0 >> num1) {
		Number small = num0 < num1 ? num0 : num1;
		Number large = num0 > num1 ? num0 : num1;
		Number max_count = 0;
		for (Number i = small; i <= large; ++ i) {
			Number count = 1;
			Number temp = i;
			while (1 != temp) {
				if (num_map.end() != num_map.find(temp)) {
					count += num_map[temp];
					break;
				}
				++ count;
				if (temp % 2) {
					temp = 3 * temp + 1;
				} else {
					temp = temp / 2;
				}
			}
			if (count > max_count) {
				max_count = count;
			}
		}
		cout << num0 << " " << num1 << " " << max_count << endl;
	}

	return 0;
}
















