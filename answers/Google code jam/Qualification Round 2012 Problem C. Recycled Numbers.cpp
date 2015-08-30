//Problem C. Recycled Numbers
//#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
using namespace std;
#include <string>
#include <sstream>

int main(int argc, char *argv[])
{
#ifdef _FILE_DEBUG_
	ifstream fin;
	fin.open("../C-small-attempt0.in");
	cin.rdbuf(fin.rdbuf()); // assign file's streambuf to cin
#ifdef _C_LAN_
	freopen("../C-small-attempt0.in", "r", stdin);
#endif
#endif
#ifdef _FILE_DEBUG_
	ofstream fout;
	fout.open("../output.txt");
	cout.rdbuf(fout.rdbuf()); // assign file's streambuf to cout
#ifdef _C_LAN_
	freopen("../output.txt", "w", stdout);
#endif
#endif

	int case_sum, begin, end, now, cnt;
	stringstream ss;
	string origin, str;
	cin >> case_sum;
	for (size_t k = 1; k <= case_sum; ++ k)
	{
		cin >> begin >> end;
		cnt = 0;
		for (int i = begin; i <= end; ++ i)
		{
			ss.clear();
			ss << i;
			ss >> origin;
			str = origin + origin;
			for (size_t j = 1; j < origin.size(); ++ j)
			{
				ss.clear();
				ss << str.substr(j, origin.size());
				ss >> now;
				if (now > 0 && i > 0 && now >= begin && now <= end && i < now)
				{
					++ cnt;
					//cout << i << " " << now << endl;
				}
			}
		}
		cout << "Case #" << k << ": " << cnt << endl;
	}

	return 0;
}