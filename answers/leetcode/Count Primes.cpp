//@type  Hash Table Math
//@result 20 / 20 test cases passed. Status: Accepted Runtime: 320 ms Submitted: 1 minute ago You are here! Your runtime beats 28.04% of cpp submissions

class Solution {
public:
    int countPrimes(int n) {
        if (prime_map.end() == prime_map.find(n)) {
			if (prime_map.size() > 0) {
				map<int, int>::iterator low = prime_map.lower_bound(n);
				prime_map.insert(make_pair(n, low->second + countPrimes(low->first + 1, n)));
			}
			else {
				prime_map.insert(make_pair(n, countPrimes(1, n)));
			}
		}
		return prime_map[n];
    }
    int countPrimes(int left, int right) {
		int count(0);
		if (right >= prime_flag.size()) {
			setPrimes(right);
		}
		for (int i = left; i < right; ++ i) {
			if (prime_flag[i]) {
				++ count;
			}
		}
		return count;
	}
	void setPrimes(int num) {
		prime_flag.clear();
		prime_flag.resize(num + 1, true);
		prime_flag[0] = false;
		prime_flag[1] = false;
		for (int i = 2; i * i <= num; ++ i) {
			if (prime_flag[i]) {
				for (int j = i * i; j <= num; j += i) {
					prime_flag[j] = false;
				}
			}
		}
	}
	vector<bool> prime_flag;
	map<int, int> prime_map;
};