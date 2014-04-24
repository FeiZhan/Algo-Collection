//
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	int case_num;
	cin >> case_num;
	for (int i = 0; i < case_num; ++i)
	{
		long long a, b, c, sum;
		cin >> a >> b >> c;
		sum = a + b;
		bool flag;
		// check overflow, note =
		if (a > 0 && b > 0 && sum <= 0)
		{
			flag = true;
		}
		else if (a < 0 && b < 0 && sum >= 0)
		{
			flag = false;
		}
		else
		{
			flag = sum > c;
		}
		cout << "Case #" << i + 1 << ": " << (flag ? "true" : "false") << endl;
	}
	return 0;
}