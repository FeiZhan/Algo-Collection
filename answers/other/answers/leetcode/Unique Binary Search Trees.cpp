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
