// copied from leetcode discussion
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		long long div1 = abs(static_cast<double>(dividend));
		long long div2 = abs(static_cast<double>(divisor));
		int ans = 0;
		while (div1 >= div2)
		{
			long long tmp = div2;
			for (int i = 0; div1 >= tmp; ++ i, tmp <<= 1)
			{
				div1 -= tmp;
				ans += 1 << i;
			}
		}
		if ((dividend >= 0 && divisor >= 0) || (dividend < 0 && divisor < 0))
		{
			return ans;
		} else
		{
			return - ans;
		}
    }
};
