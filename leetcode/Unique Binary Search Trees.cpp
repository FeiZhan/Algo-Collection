class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 0)
        {
			return 0;
		} else if (1 == n)
		{
			return 1;
		}
		int count = 0;
		for (int i = 0; i < n; ++ i)
		{
			if (0 == i || n - 1 == i)
			{
				count += numTrees(n - 1);
			} else
			{
				count += numTrees(i) * numTrees(n - i - 1);
			}
		}
		return count;
    }
};
