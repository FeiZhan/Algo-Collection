//@type Hash Table Math
//@result 400 / 400 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 0 minutes ago You are here! Your runtime beats 29.67% of cpp submissions.

class Solution {
public:
    bool isHappy(int n) {
        set<int> happy_list;
		return isHappy(n, happy_list);
    }
	bool isHappy(int n, set<int> &happy_list) {
		if (1 == n) {
			return true;
		}
		int sum(0);
		while (n) {
			sum += (n % 10) * (n % 10);
			n /= 10;
		}
		if (happy_list.end() != happy_list.find(sum)) {
			return false;
		}
		happy_list.insert(sum);
		return isHappy(sum, happy_list);
	}
};