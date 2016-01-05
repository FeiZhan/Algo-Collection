//@result 34 / 34 test cases passed. Status: Accepted Runtime: 0 ms Submitted: 0 minutes ago You are here! Your runtime beats 12.14% of cpp submissions.

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		std::vector<int> row;
		row.push_back(1);
		if (0 == rowIndex)
		{
			return row;
		}
		if (1 == rowIndex)
		{
			row.push_back(1);
			return row;
		}
		for (int i = 1; i <= rowIndex; ++ i)
		{
			for (int j = 0; j + 1 < row.size(); ++ j)
			{
				row[j] = row[j] + row[j + 1];
			}
			row.insert(row.begin(), 1);
		}
		return row;
    }
};
