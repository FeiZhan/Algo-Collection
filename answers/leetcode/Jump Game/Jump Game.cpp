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
