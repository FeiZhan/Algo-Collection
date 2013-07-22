class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool negative = false;
        if (x < 0)
        {
			negative = true;
			x *= -1;
		}
		int ans = 0;
		while (x > 0)
		{
			int digit = x % 10;
			long long tmp = static_cast<long long>(ans * 10) + digit;
			if (tmp > INT_MAX)
			{
				ans = INT_MAX;
			} else
			{
				ans = static_cast<int>(tmp);
			}
			x /= 10;
		}
		if (negative)
		{
			ans *= -1;
		}
		return ans;
    }
};
