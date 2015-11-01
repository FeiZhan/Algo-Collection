//@level Medium 
//@type Enumeration Basic Implementation String LintCode Copyright
//@result Accepted 100% Total Runtime: 15 ms 100% test cases passed.

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
		if (0 == strs.size()) {
			return string();
		}
		string prefix(strs[0]);
		for (size_t i = 1; i < strs.size(); ++ i) {
			prefix = prefix.substr(0, strs[i].length());
			for (size_t j = 0; j < prefix.length() && j < strs[i].length(); ++ j) {
				if (strs[i][j] != prefix[j]) {
					prefix.erase(j);
					break;
				}
			}
		}
		return prefix;
    }
};
