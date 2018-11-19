// not recommended
class Solution {
public:
    int maximumGap(vector<int> &num) {
		if (num.size() < 2) {
			return 0;
		}
		std::sort(num.begin(), num.end());
		int max_gap = 0;
		for (size_t i = 1; i < num.size(); ++ i) {
			if (num[i] - num[i - 1] > max_gap) {
				max_gap = num[i] - num[i - 1];
			}
		}
		return max_gap;
    }
};

