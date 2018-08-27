//@result 19 / 19 test cases passed. Status: Accepted Runtime: 0 ms Submitted: 0 minutes ago You are here! Your runtime beats 3.39% of cpp submissions.

class Solution {
public:
	Solution(void) {
		num_map[0] = 1;
		num_map[1] = 1;
	}
    int numTrees(int n) {
		if (num_map.end() != num_map.find(n)) {
			return num_map[n];
		}
		int num = 0;
		for (int i = 0; i < n; ++ i) {
			num += numTrees(i) * numTrees(n - 1 - i);
		}
		num_map[n] = num;
		return num;
    }
    std::map<int, int> num_map;
};
