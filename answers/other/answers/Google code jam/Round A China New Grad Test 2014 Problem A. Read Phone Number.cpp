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

#include <string>
#include <sstream>

int main(int argc, char *argv[])
{
#ifdef _FILE_DEBUG_
	ifstream fin;
	fin.open("../input.txt");
	cin.rdbuf(fin.rdbuf());
#ifdef _C_LAN_
	freopen("../input.txt", "r", stdin);
#endif
#endif
#ifdef _FILE_DEBUG_
	ofstream fout;
	fout.open("../output.txt");
	cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("../output.txt", "w", stdout);
#endif
#endif

	const std::string NUM[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	const std::string SUCCESSIVE[11] = {"error0", "error1", "double", "triple", "quadruple", "quintuple", "sextuple", "septuple", "octuple", "nonuple", "decuple"};
	int case_num;
	std::cin >> case_num;
	for (int i = 0; i < case_num; ++ i)
	{
		std::string number, rule, ans;
		std::cin >> number >> rule;
		int pos = 0;
		std::stringstream ss;
		ss << rule;
		int divide;
		char tmp;
		while (ss >> divide)
		{
			ss >> tmp;
//cout << "debug0 " << pos <<  " " << divide << " " << number.substr(pos, divide) << endl;
			if (divide == 1)
			{
				ans += NUM[static_cast<int>(number[pos] - '0')] + " ";
			} else
			{
				for (int j = 1; j < divide; ++ j)
				{
//cout << "debug1 " << j << " " << number[pos + j - 1] << endl;
					if (number[pos + j] == number[pos + j - 1])
					{
						int k = 0;
						while (number[pos + j + k] == number[pos + j - 1] && j + k < divide && k < 11)
						{
							++ k;
						}
						ans += SUCCESSIVE[k + 1] + " " + NUM[static_cast<int>(number[pos + j - 1] - '0')] + " ";
						j += k;
					} else
					{
						ans += NUM[static_cast<int>(number[pos + j - 1] - '0')] + " ";
						if (divide - 1 == j)
						{
//cout << "debug2 " << j << " " << number[pos + j] << endl;
							//ans += NUM[static_cast<int>(number[pos + j] - '0')] + " ";
						}
					}
//cout << "debug3 end " << j << " < " << divide << endl;
				}
				if (divide > 1 && number[pos + divide - 1] != number[pos + divide - 2])
				{
					ans += NUM[static_cast<int>(number[pos + divide - 1] - '0')] + " ";
				}
			}
			pos += divide;
		}
		while (ans[ans.length() - 1] == ' ')
		{
			ans.erase(ans.length() - 1, 1);
		}
		std::cout << "Case #" << i + 1 << ": " << ans << std::endl;
	}

	return 0;
}
