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
