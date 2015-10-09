//@type Hash Table Sort
//@result 81 / 81 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 5 minutes ago

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), std::greater<int> ());
		for (size_t i = 0; i < citations.size(); ++ i) {
			if (citations[i] <= i) {
				return i;
			}
		}
		return citations.size();
    }
};