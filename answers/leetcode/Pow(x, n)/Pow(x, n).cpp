// recursive
//@result 299 / 299 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 0 minutes ago You are here! Your runtime beats 8.54% of cpp submissions.

class Solution {
public:
    double myPow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if (0 == n)
		{
			return 1.0;
		}
		double half = pow(x, n / 2);
		if (0 == n % 2)
		{
			return half * half;
		}
		else if (n > 0)
		{
			return half * half * x;
		} else
		{
			return half * half / x;
		}
    }
};
