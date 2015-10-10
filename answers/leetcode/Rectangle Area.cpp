//@type Math
//@result 3081 / 3081 test cases passed. Status: Accepted Runtime: 32 ms Submitted: 0 minutes ago You are here! Your runtime beats 24.41% of cpp submissions.

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (D - B) * (C - A) + (H - F) * (G - E);
		if (A >= G || B >= H || C <= E || D <= F) {
			return area;
		}
		return area - (min(D, H) - max(B, F)) * (min(C, G) - max(A, E));
    }
};