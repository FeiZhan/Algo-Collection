class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		vector<bool> dp(s.length(), true);
		set<string> ans = dfs(0, s, dict, dp);
		return vector<string> (ans.begin(), ans.end());
	}
	set<string> dfs(size_t begin, const string &s, const unordered_set<string> &dict, vector<bool> &dp) {
		set<string> ans;
		if (! dp[begin]) {
			return ans;
		}
		for (unordered_set<string>::const_iterator it = dict.begin(); it != dict.end(); ++ it) {
			string word = s.substr(begin, it->length());
			if (*it != word) {
				continue;
			}
			if (begin + it->length() == s.length()) {
				ans.insert(word);
			}
			set<string> rest = dfs(begin + it->length(), s, dict, dp);
			for (set<string>::iterator it1 = rest.begin(); it1 != rest.end(); ++ it1) {
				ans.insert(word + " " + *it1);
			}
		}
		if (0 == ans.size()) {
			dp[begin] = false;
		}
		return ans;
	}
};
