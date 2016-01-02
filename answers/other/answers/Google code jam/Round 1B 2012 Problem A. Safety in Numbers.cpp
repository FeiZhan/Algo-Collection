//Problem A. Safety in Numbers
//#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
using namespace std;
#include <iomanip>

int main(int argc, char *argv[])
{
#ifdef _FILE_DEBUG_
	ifstream fin;
	fin.open("../A-small-attempt5.in");
	cin.rdbuf(fin.rdbuf()); // assign file's streambuf to cin
#ifdef _C_LAN_
	freopen("../A-small-attempt3.in", "r", stdin);
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

	int case_sum, score_sum, score[210], sum;
	double ans;
	cin >> case_sum;
	for (int i = 1; i <= case_sum; ++ i)
	{
		cin >> score_sum;
		sum = 0;
		for (int j = 0; j < score_sum; ++ j)
		{
			cin >> score[j];
			sum += score[j];
		}
		cout << "Case #" << i << ":";
		for (int j = 0; j < score_sum; ++ j)
		{
			ans = (2.0 / score_sum - 1.0 * score[j] / sum) * 100.0;
			cout << " ";
			if (ans <= 0)
			{
				cout << setiosflags(ios::fixed) << setprecision(6) << 0.000000;
			}
			else if (ans >= 100)
			{
				cout << setiosflags(ios::fixed) << setprecision(6) << 100.000000;
			}
			else if (ans == int(ans))
			{
				cout << setiosflags(ios::fixed) << setprecision(1)
						<< ans;
			}
			else
			{
				ans *= 10000.0;
				if (ans == int(ans))
				{
					cout << resetiosflags(ios::fixed) << ans / 10000.0;
				}
				else
				{
					cout << setiosflags(ios::fixed) << setprecision(6)
						<< ans / 10000.0;
				}
			}
		}
		cout << endl;
	}

	return 0;
}