class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, pair<int, bool> > letter_map;
        for (size_t i = 0; i < s.length(); ++ i) {
            if (letter_map.end() == letter_map.find(s[i])) {
                letter_map.insert(make_pair(s[i], make_pair(0, false)));
            }
            ++ letter_map[s[i]].first;
        }
        stack<char> letter_stack;
        for (size_t i = 0; i < s.length(); ++ i) {
            -- letter_map[s[i]].first;
            if (! letter_map[s[i]].second) {
                while (letter_stack.size() > 0 && letter_stack.top() > s[i] && letter_map[letter_stack.top()].first > 0) {
                    letter_map[letter_stack.top()].second = false;
                    letter_stack.pop();
                }
                letter_stack.push(s[i]);
                letter_map[s[i]].second = true;
            }
        }
        string no_duplicate;
        while (! letter_stack.empty()) {
            no_duplicate = letter_stack.top() + no_duplicate;
            letter_stack.pop();
        }
        return no_duplicate;
    }
};
