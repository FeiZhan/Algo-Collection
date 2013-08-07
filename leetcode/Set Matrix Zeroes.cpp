//WA
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void printMat(const vector<vector<int> > &matrix)
{
	for (unsigned i = 0; i < matrix.size(); ++ i)
	{
		for (unsigned j = 0; j <matrix[i].size(); ++ j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (unsigned i = 0; i < matrix.size(); ++ i)
        {
			for (unsigned j = 0; j < matrix[i].size(); ++ j)
			{
				if (0 == matrix[i][j])
				{
//cout << "testing ij " << i << " " << j << endl;
					for (unsigned k = 0; k < matrix.size(); ++ k)
					{
//cout << "testing k1 " << k << endl;
						if (INT_MIN == matrix[k][j] || 0 == matrix[k][j])
						{
							continue;
						} else
						{
							matrix[k][j] = INT_MIN;
						}
					}
					for (unsigned k = 0; k < matrix[i].size(); ++ k)
					{
//cout << "testing k2 " << k << endl;
						if (INT_MIN == matrix[i][k] || 0 == matrix[i][k])
						{
//cout << "testing k2 case2 " << k << endl;
							continue;
						} else
						{
//cout << "testing k2 case3 " << k << endl;
							matrix[i][k] = INT_MIN;
						}
					}
				}
//cout << "testing " << endl;
	//printMat(matrix);
			}
		}
        for (unsigned i = 0; i < matrix.size(); ++ i)
        {
			for (unsigned j = 0; j < matrix[i].size(); ++ j)
			{
				if (INT_MIN == matrix[i][j])
				{
					matrix[i][j] = 0;
				}
			}
		}
    }
};
int main(int argc, char *argv[])
{
	vector<vector<int> > matrix;
	vector<int> tmp;
	Solution s;
	//[[0,1]]
	matrix.clear();
	tmp.clear();
	tmp.push_back(0);
	tmp.push_back(1);
	matrix.push_back(tmp);
	s.setZeroes(matrix);
	printMat(matrix);
	//[[0,0,0,5],[4,3,1,4],[0,1,1,4],[1,2,1,3],[0,0,1,1]]	[[0,0,0,0],[0,0,0,4],[0,0,0,4],[0,0,0,3],[0,0,0,1]]	[[0,0,0,0],[0,0,0,4],[0,0,0,0],[0,0,0,3],[0,0,0,0]]	

	return 0;
}
