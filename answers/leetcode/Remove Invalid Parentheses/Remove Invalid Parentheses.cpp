class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        set<string> valid_list;
        string invalid = s;
        removeInvalidParentheses(0, invalid, s, valid_list);
        return vector<string> (valid_list.begin(), valid_list.end());
    }
    void removeInvalidParentheses(size_t current, string &s, const string &origin, set<string> &valid_list) {
        //cout << "debug " << current << " |" << s << endl;
        size_t left = INT_MAX;
        bool flag = false;
        for (size_t i = current; i < s.length(); ++ i) {
            if ('(' == s[i]) {
                left = i;
                s[left] = ' ';
                for (size_t j = left + 1; j < s.length(); ++ j) {
                    if (')' == s[j]) {
                        flag = true;
                        s[j] = ' ';
                        removeInvalidParentheses(left + 1, s, origin, valid_list);
                        s[j] = ')';
                    }
                }
                s[left] = '(';
            }
        }
        if (left >= s.length() || ! flag) {
            string valid = origin;
            int count = origin.length();
            for (size_t i = 0; i < s.size(); ++ i) {
                if ('(' == s[i] || ')' == s[i]) {
                    valid[i] = ' ';
                    -- count;
                }
            }
            if (valid_list.size() > 0 && count > valid_list.begin()->length()) {
                valid_list.clear();
            }
            if (0 == valid_list.size() || count >= valid_list.begin()->length()) {
                for (size_t i = 0; i < valid.size(); ++ i) {
                    if (' ' == valid[i]) {
                        valid.erase(i, 1);
                        -- i;
                    }
                }
                valid_list.insert(valid);
            }
        }
    }
};