class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0)
        {
			return false;
		}
        return (isPalin(x, 0) < 0);
    }
    int isPalin(int num, int pos)
    {
		if (num / get10(pos) < 10)
		{
			return -1;
		}
		int comp = isPalin()
	}
	long long get10(int order)
	{
		long long ten = 1;
		for (int i = 0; i < order; ++ i)
		{
			ten *= 10;
		}
		return ten;
	}
};
