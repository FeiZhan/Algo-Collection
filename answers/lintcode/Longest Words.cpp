//@level Easy 
//@type Enumeration String LintCode Copyright
//@result Accepted Total Runtime: 257 ms 100% test cases passed.

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
		vector<string> longest;
		int length(0);
		for (size_t i = 0; i < dictionary.size(); ++ i) {
			if (dictionary[i].length() > length) {
				longest.clear();
				length = dictionary[i].length();
			}
			if (dictionary[i].length() >= length) {
				longest.push_back(dictionary[i]);
			}
		}
		return longest;
    }
};
