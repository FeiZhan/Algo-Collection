//@result Accepted Total Runtime: 144 ms 100% test cases passed.

class Solution {
public:
    /**
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
		long long sum = std::accumulate(L.begin(), L.end(), (long long) (0));
		if (sum < k) {
			return 0;
		}
		long long left = 0;
		long long right = *std::max_element(L.begin(), L.end());
        // note boundary case in binary search
		while (left + 1 < right) {
			long long middle = (left + right) / 2;
			long long count = 0;
			for (size_t i = 0; i < L.size(); ++ i) {
				count += L[i] / middle;
			}
			if (count < k) {
				right = middle - 1;
			}
			else if (count >= k) {
				left = middle;
			}
		}
        // test left and right
        long long count = 0;
        for (size_t i = 0; i < L.size(); ++ i) {
            count += L[i] / right;
        }
		return count >= k ? right : left;
    }
};
