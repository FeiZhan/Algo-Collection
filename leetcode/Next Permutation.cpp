// copied from leetcode discussion

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		std::vector<int>::iterator it = num.end() - 1;
		// find the first ascending pair from end
		while (it != num.begin() && *(it - 1) >= *it)
		{
			-- it;
		}
		// if it is the begin, reverse to the first permutation
		if (num.begin() == it)
		{
			std::reverse(num.begin(), num.end());
			return;
		}
		// the first element to swap
		-- it;
		vector<int>::iterator it2 = it + 1;
		// find the smallest one larger than *it
		while (it2 != num.end() && *it2 > *it)
		{
			++ it2;
		}
		-- it2;
		std::iter_swap(it, it2);
		// reverse to ascending order
		std::reverse(it + 1, num.end());
    }
};

// 2015-01-10
class Solution {
public:
	void nextPermutation(vector<int> &num) {
		size_t vio_pos = INT_MAX;
		for (size_t i = num.size() - 2; i < num.size(); --i) {
			if (num[i] < num[i + 1]) {
				vio_pos = i;
				break;
			}
		}
		if (vio_pos != INT_MAX) {
			size_t change_pos = 0;
			size_t min_change = INT_MAX;
			for (size_t i = num.size() - 1; i > vio_pos; --i) {
				if (num[i] > num[vio_pos] && num[i] <= min_change) {
					change_pos = i;
					min_change = num[i];
				}
			}
			int temp = num[vio_pos];
			num[vio_pos] = num[change_pos];
			num[change_pos] = temp;
			sort(num.begin() + vio_pos + 1, num.end());
		}
		else {
			sort(num.begin(), num.end());
		}
	}
};