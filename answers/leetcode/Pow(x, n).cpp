// idea from leetcode
// recursive

class Solution {
public:
    double pow(double x, int n) {
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
