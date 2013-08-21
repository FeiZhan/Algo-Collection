// copied from leetcode discussion
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		std::vector<int>::iterator it = num.end() - 1;
		while (it != num.begin() && *(it - 1) >= *it)
		{
			-- it;
		}
		if (num.begin() == it)
		{
			std::reverse(num.begin(), num.end());
			return;
		}
		-- it;
		vector<int>::iterator it2 = it + 1;
		while (it2 != num.end() && *it2 > *it)
		{
			++ it2;
		}
		-- it2;
		std::iter_swap(it, it2);
		std::reverse(it + 1, num.end());
    }
};
