#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		return spiral(matrix, 0);
    }
    vector<int> spiral(const vector<vector<int> > &matrix, const int level)
    {
		vector<int> ans;
		if (matrix.size() == 0 || level * 2 + 1 > matrix.size() || level * 2 + 1 > matrix[0].size())
		{
			return ans;
		}
		// up
		for (int i = level; i < matrix[0].size() - level; ++ i)
		{
			ans.push_back(matrix[level][i]);
		}
		// right
		for (int i = level + 1; i < matrix.size() - level; ++ i)
		{
			ans.push_back(matrix[i][matrix[0].size() - level - 1]);
		}
		if (matrix.size() > level * 2 + 1)
		{
			// down
			for (int i = level + 1; i < matrix[0].size() - level; ++ i)
			{
				ans.push_back(matrix[matrix.size() - level - 1][matrix[0].size() - i - 1]);
			}
		}
		if (matrix[0].size() > level * 2 + 1)
		{
			// left
			for (int i = level + 1; i < matrix.size() - level - 1; ++ i)
			{
				ans.push_back(matrix[matrix.size() - i - 1][level]);
			}
		}
		vector<int> child = spiral(matrix, level + 1);
		ans.reserve( ans.size() + child.size() );
		ans.insert( ans.end(), child.begin(), child.end() );
		return ans;
	}
};
int main()
{
	Solution s;
	vector<vector<int> > matrix;
	vector<int> tmp;
	//[[2,3]]
	//[[1,2],[3,4]]
	//[[1,2,3,4],[5,6,7,8],[9,10,11,12]]
	tmp.clear();
	tmp.push_back(1);
	tmp.push_back(2);
	tmp.push_back(3);
	tmp.push_back(4);
	matrix.push_back(tmp);
	tmp.clear();
	tmp.push_back(5);
	tmp.push_back(6);
	tmp.push_back(7);
	tmp.push_back(8);
	matrix.push_back(tmp);
	tmp.clear();
	tmp.push_back(9);
	tmp.push_back(10);
	tmp.push_back(11);
	tmp.push_back(12);
	matrix.push_back(tmp);
	vector<int> ans = s.spiralOrder(matrix);
	for (int i = 0; i < ans.size(); ++ i)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
