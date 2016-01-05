//@result 43 / 43 test cases passed. Status: Accepted Runtime: 12 ms Submitted: 0 minutes ago You are here! Your runtime beats 15.30% of cpp submissions.

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // write your code here
		for (size_t i = 1; i < triangle.size(); ++ i) {
			for (size_t j = 0; j < triangle[i].size(); ++ j) {
				triangle[i][j] += min((j > 0 ? triangle[i - 1][j - 1] : INT_MAX), (j < triangle[i - 1].size() ? triangle[i - 1][j] : INT_MAX));
				//cout << "test " << i << " " << j << " " << triangle[i][j] << endl;
			}
		}
		int min_total = INT_MAX;
		for (size_t i = 0; i < triangle.back().size(); ++ i) {
			min_total = min(min_total, triangle.back()[i]);
		}
		return min_total;
    }
};
