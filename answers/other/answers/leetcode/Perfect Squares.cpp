//@type  Dynamic Programming Breadth-first Search Math
//@result 600 / 600 test cases passed. Status: Accepted Runtime: 404 ms Submitted: 0 minutes ago

class Solution {
public:
    int numSquares(int n) {
		vector<int> square_list(n + 1, INT_MAX);
		square_list[0] = 0;
        for (int i = 0; i <= n; ++ i) {
			for (int j = 1; i + j * j <= n; ++ j) {
				square_list[i + j * j] = min(square_list[i + j * j], square_list[i] + 1);
			}
		}
		return square_list[n];
    }
};