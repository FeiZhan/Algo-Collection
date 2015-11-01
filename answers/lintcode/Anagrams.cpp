//@level Medium
//@type String Hash Table
//@result Accepted Total Runtime: 60 ms 100% test cases passed.

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
		map<string, vector<size_t> > anagram_map;
		for (size_t i = 0; i < strs.size(); ++ i) {
			string anagram = strs[i];
			sort(anagram.begin(), anagram.end());
			if (anagram_map.end() == anagram_map.find(anagram)) {
				anagram_map[anagram] = vector<size_t> ();
			}
			anagram_map[anagram].push_back(i);
		}
		vector<string> anagram_list;
		for (map<string, vector<size_t> >::iterator it = anagram_map.begin(); it != anagram_map.end(); ++ it) {
			if (it->second.size() > 1) {
				for (size_t i = 0; i < it->second.size(); ++ i) {
					anagram_list.push_back(strs[it->second[i]]);
				}
			}
		}
		return anagram_list;
    }
};

