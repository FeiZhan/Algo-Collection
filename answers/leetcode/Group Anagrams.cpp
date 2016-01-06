//@result 100 / 100 test cases passed. Status: Accepted Runtime: 88 ms Submitted: 0 minutes ago You are here! Your runtime beats 33.86% of cpp submissions.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        unordered_map<string, vector<size_t> > anagram_map;
        for (size_t i = 0; i < strs.size(); ++ i) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            anagram_map[temp].push_back(i);
        }
        vector<vector<string> > anagram_list;
        for (unordered_map<string, vector<size_t> >::iterator it = anagram_map.begin(); it != anagram_map.end(); ++ it) {
            vector<string> temp;
            for (size_t i = 0; i < it->second.size(); ++ i) {
                temp.push_back(strs[it->second[i]]);
            }
            anagram_list.push_back(temp);
        }
        return anagram_list;
    }
};
