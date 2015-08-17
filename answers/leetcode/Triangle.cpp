//
/*#include <iostream>
#include <stdio.h>
#define FILE_DEBUG
//#define _C_LAN_
#ifdef FILE_DEBUG
#include <fstream>
#endif
using namespace std;

#include <vector>*/

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > path;
        for (int i = 0; i < triangle.size(); ++ i)
        {
			vector<int> tmp;
			for (int j = 0; j < triangle[i].size(); ++ j)
			{
				tmp.push_back(0);
			}
			path.push_back(tmp);
		}
        for (int i = triangle.size() - 1; i >= 0; -- i)
        {
			for (int j = 0; j < triangle[i].size(); ++ j)
			{
				if (triangle.size() - 1 == i)
				{
					path[i][j] = triangle[i][j];
				} else
				{
					
					if (path[i + 1][j] > path[i + 1][j + 1])
					{
						path[i][j] = triangle[i][j] + path[i + 1][j + 1];
					} else
					{
						path[i][j] = triangle[i][j] + path[i + 1][j];
					}
				}
			}
		}
		if (path.size() == 0 || path[0].size() == 0)
		{
			return 0;
		} else
		{
			return path[0][0];
		}
    }
};

/*int main(int argc, char *argv[])
{
#ifdef FILE_DEBUG
	ifstream fin;
	fin.open("input.txt");
	cin.rdbuf(fin.rdbuf()); // assign file's streambuf to cin
#ifdef _C_LAN_
	freopen("input.txt", "r", stdin);
#endif
#endif
#ifdef FILE_DEBUG
	ofstream fout;
	fout.open("output.txt");
	cout.rdbuf(fout.rdbuf()); // assign file's streambuf to cout
#ifdef _C_LAN_
	freopen("output.txt", "w", stdout);
#endif
#endif

    // Start typing your code here...
    vector<vector<int> > triangle;
    vector<int> row;
    int count = 0, a;
    while (cin >> a)
    {
		++ count;
		row.push_back(a);
		if (0 == triangle.size() || count >= triangle[triangle.size() - 1].size())
		{
			count = 0;
			triangle.push_back(row);
			row.clear();
		}
	}
	for (int i = 0; i < triangle.size(); ++ i)
	{
		for (int j = 0; j < triangle[i].size(); ++ j)
		{
			cout << triangle[i][j] << " ";
		}
		cout << endl;
	}
	Solution s;
	std::cout << s.minimumTotal(triangle) << std::endl;
    return 0;
}*/
// 2014-04-11, DP from bottom to top
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		if (triangle.size() == 0)
		{
			return 0;
		}
		std::vector<int> sums(triangle.back());
		for (std::vector<std::vector<int> >::reverse_iterator it = triangle.rbegin() + 1; it != triangle.rend(); ++it)
		{
			for (size_t j = 0; j < it->size(); ++j)
			{
				sums[j] = it->at(j) + std::min(sums[j], sums[j + 1]);
			}
		}
		return sums[0];
	}
};