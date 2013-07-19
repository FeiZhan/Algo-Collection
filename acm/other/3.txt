//Problem B. Dancing With the Googlers
//#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
#ifdef _FILE_DEBUG_
	ifstream fin;
	fin.open("../B-small-attempt0.in");
	cin.rdbuf(fin.rdbuf()); // assign file's streambuf to cin
#ifdef _C_LAN_
	freopen("../B-small-attempt0.in", "r", stdin);
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

	int case_sum, per_sum, surp_sum, limit, person[120], cnt, surp_cnt, low[2];
	cin >> case_sum;
	for (size_t i = 1; i <= case_sum; ++ i)
	{
		cin >> per_sum >> surp_sum >> limit;
		cnt = surp_cnt = 0;
		low[0] = max(limit - 1, 0);
		low[1] = max(limit - 2, 0);
		for (size_t j = 0; j < per_sum; ++ j)
		{
			cin >> person[j];
			if (person[j] >= limit + 2 * low[0])
			{
				++ cnt;
			}
			else if (person[j] >= limit + 2 * low[1])
			{
				++ surp_cnt;
			}
		}
		cnt += min(surp_cnt, surp_sum);
		cout << "Case #" << i << ": " << cnt << endl;
	}

	return 0;
}