class Solution {
public:
    /**
     * @param s Roman representation
     * @return an integer
     */
    Solution(void) {
        roman_map.insert(make_pair('I', 1));
        roman_map.insert(make_pair('V', 5));
        roman_map.insert(make_pair('X', 10));
        roman_map.insert(make_pair('L', 50));
        roman_map.insert(make_pair('C', 100));
        roman_map.insert(make_pair('D', 500));
        roman_map.insert(make_pair('M', 1000));
    }
    int romanToInt(string& s) {
        // Write your code here
        int integer = 0;
        for (size_t i = 0; i < s.length(); ++ i) {
            if (i > 0 && roman_map[s[i]] > roman_map[s[i - 1]]) {
                integer += roman_map[s[i]] - roman_map[s[i - 1]] - roman_map[s[i - 1]];
            }
            else {
                integer += roman_map[s[i]];
            }
        }
        return integer;
    }
    map<char, int> roman_map;
};
