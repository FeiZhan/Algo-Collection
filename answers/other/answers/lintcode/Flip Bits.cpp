class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
		a ^= b;
		int count = 0;
		// if negative, while loop cannot end
		for (int i = 0; i < 32; ++ i) {
			count += a & 1;
			a >>= 1;
		}
		return count;
    }
};
