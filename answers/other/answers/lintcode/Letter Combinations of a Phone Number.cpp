class Solution {
public:
    Solution(void) {
        num_map['0'] = string(" ");
        num_map['1'] = string("");
        num_map['2'] = string("abc");
        num_map['3'] = string("def");
        num_map['4'] = string("ghi");
        num_map['5'] = string("jkl");
        num_map['6'] = string("mno");
        num_map['7'] = string("pqrs");
        num_map['8'] = string("tuv");
        num_map['9'] = string("wxyz");
    }
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    vector<string> letterCombinations(string& digits) {
        // Write your code here
        vector<string> ans = letterCombinations(0, digits);
        sort(ans.begin(), ans.end());
        return ans;
    }
    std::vector<string> letterCombinations(size_t index, const string &digits) {
        std::vector<string> combinations;
        if (index < digits.length()) {
            std::vector<string> next = letterCombinations(index + 1, digits);
            if (next.size() == 0) {
                next.push_back(string ());
            }
            for (size_t i = 0; i < next.size(); ++ i) {
                for (size_t j = 0; j < num_map[digits[index]].size(); ++ j) {
                    combinations.push_back(num_map[digits[index]][j] + next[i]);
                }
            }
        }
        return combinations;
    }
    std::map<char, string> num_map;
};
