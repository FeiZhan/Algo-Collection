// simply iterate, copied from leetcode

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		std::vector<std::vector<int> > ans(n, std::vector<int>(n));
		int start = 0, end = n - 1, num = 1;
		while (start < end)
		{
			for (int i = start; i < end; ++ i)
			{
				ans[start][i] = num;
				++ num;
			}
			for (int i = start; i < end; ++ i)
			{
				ans[i][end] = num;
				++ num;
			}
			for (int i = end; i > start; -- i)
			{
				ans[end][i] = num;
				++ num;
			}
			for (int i = end; i > start; -- i)
			{
				ans[i][start] = num;
				++ num;
			}
			++ start;
			-- end;
		}
		if (start == end)
		{
			ans[start][end] = num;
		}
		return ans;
    }
};

// 2015-01-10
// recursion
class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		if (mat_map.end() != mat_map.find(n)) {
			return mat_map[n];
		}
		vector<vector<int> > mat;
		if (n <= 0) {
			return mat;
		}
		if (1 == n) {
			mat.push_back(vector<int>(1, 1));
			mat_map[n] = mat;
			return mat;
		}
		else if (2 == n) {
			mat.assign(2, vector<int> (2, 0));
			mat[0][0] = 1;
			mat[0][1] = 2;
			mat[1][0] = 4;
			mat[1][1] = 3;
			mat_map[n] = mat;
			return mat;
		}
		mat = generateMatrix(n - 2);
		for (size_t i = 0; i < mat.size(); ++i) {
			for (size_t j = 0; j < mat[i].size(); ++j) {
				mat[i][j] += (n - 1) * 4;
			}
			mat[i].insert(mat[i].begin(), (n - 1) * 4 - i);
			mat[i].push_back(n + 1 + i);
		}
		vector<int> first_line(n, 0);
		vector<int> last_line(n, 0);
		for (size_t i = 0; i < n; ++i) {
			first_line[i] = i + 1;
			last_line[n - 1 - i] = (n - 1) * 2 + 1 + i;
		}
		mat.insert(mat.begin(), first_line);
		mat.push_back(last_line);
		mat_map[n] = mat;
		return mat;
	}
	map<int, vector<vector<int> > > mat_map;
};