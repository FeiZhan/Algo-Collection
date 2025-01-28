//@type  Hash Table
//@result 26 / 26 test cases passed. Status: Accepted Runtime: 0 ms Submitted: 0 minutes ago

class Solution {
public:
    bool wordPattern(string pattern, string str) {
		istringstream iss(str);
		vector<string> tokens{istream_iterator<string>{iss}, istream_iterator<string>{}};
		if (pattern.length() != tokens.size()) {
			return false;
		}
		set<string> word_set;
		map<char, string> word_map;
		for (size_t i = 0; i < pattern.length(); ++ i) {
			if (word_map.end() == word_map.find(pattern[i])) {
				if (word_set.end() != word_set.find(tokens[i])) {
					return false;
				}
				word_set.insert(tokens[i]);
				word_map.insert(make_pair(pattern[i], tokens[i]));
			}
			else if (word_map[pattern[i]] != tokens[i]) {
				return false;
			}
		}
		return true;
    }
};