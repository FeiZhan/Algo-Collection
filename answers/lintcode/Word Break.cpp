//@result TLE

class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, unordered_set<string> &dict) {
        // write your code here
		vector<bool> dp(s.length(), false);
		for (size_t i = 0; i < s.length(); ++ i) {
			if (dict.end() != dict.find(s.substr(0, i + 1))) {
				dp[i] = true;
			}
			else {
				for (size_t j = i - 1; j < i && j < s.length(); -- j) {
					if (dp[j] && dict.end() != dict.find(s.substr(j + 1, i - j))) {
						dp[i] = true;
						break;
					}
				}
			}
		}
		return dp.size() ? dp[dp.size() - 1] : true;
    }
};
