class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
		sort(str.begin(), str.end());
		return unique(str.begin(), str.end()) == str.end();
    }
};
