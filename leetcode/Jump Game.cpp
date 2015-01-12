//WA
class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 0)
        {
			return false;
		}
		if (A[0] >= n - 1)
		{
			return true;
		}
		int sum = 0, index = 0;
		while (index < n)
		{
			sum += A[index];
			if (0 == A[index])
			{
				break;
			}
			index += A[index];
		}
		if (sum >= n - 1)
		{
			return true;
		}
		sum = 0, index = 0;
		while (index < n)
		{
			sum += A[index];
			if (0 == A[index])
			{
				break;
			}
			++ index;
		}
		if (sum >= n - 1)
		{
			return true;
		}
        vector<bool> can(n, false);
        can[n - 1] = true;
		for (int i = n - 2; i >= 0; -- i)
		{
			for (int j = A[i]; j >= 0; -- j)
			{
				if (i + j >= n)
				{
					continue;
				}
				if (can[i + j])
				{
					can[i] = true;
					break;
				}
			}
		}
		return can[0];
    }
};

//@type greedy, only one loop
class Solution {
public:
    bool canJump(int A[], int n) {
		int can_jump = 0;
		for (int i = 0; i <= can_jump; ++ i)
		{
			can_jump = std::max(can_jump, i + A[i]);
			if (can_jump >= n - 1)
			{
				return true;
			}
		}
		return false;
    }
};
