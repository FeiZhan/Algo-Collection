#include <iostream>
#include <vector>
using namespace std;
int main (int argc, char *argv[])
{
	long long num1, num2;
	std::vector<int> num_vec;
	while (std::cin >> num1 >> num2)
	{
		num1 += num2;
		if (num1 < 0)
		{
			std::cout << "-";
			num1 *= -1;
		}
		num_vec.clear();
		while (num1 > 0)
		{
			num_vec.push_back(num1 % 10);
			num1 /= 10;
		}
		for (int i = num_vec.size() - 1; i >= 0; -- i)
		{
			cout << num_vec[i];
			if (0 != i && i % 3 == 0)
			{
				cout << ",";
			}
		}
		if (0 == num_vec.size())
		{
			cout << 0;
		}
		cout << std::endl;
	}
	return 0;
}
