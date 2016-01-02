#include <iostream>
using namespace std;
int main (int argc, char *argv[])
{
	int num, count;
	while (std::cin >> num)
	{
		count = 0;
		while (num != 1)
		{
			num = (num % 2) ? (3 * num + 1) / 2 : num / 2;
			++ count;
		}
		std::cout << count << std::endl;
	}
	return 0;
}
