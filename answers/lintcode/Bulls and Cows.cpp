class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        int cow = 0;
        map<char, int> char_map;
        for (size_t i = 0; i < secret.size() && i < guess.size(); ++ i) {
            if (secret[i] == guess[i]) {
                ++ bull;
            }
            else {
                if (char_map.end() == char_map.find(secret[i])) {
                    char_map.insert(make_pair(secret[i], 0));
                }
                else if (char_map[secret[i]] < 0) {
                    ++ cow;
                }
                ++ char_map[secret[i]];
                if (char_map.end() == char_map.find(guess[i])) {
                    char_map.insert(make_pair(guess[i], 0));
                }
                else if (char_map[guess[i]] > 0) {
                    ++ cow;
                }
                -- char_map[guess[i]];
            }
        }
        string ans;
        ans = to_string(bull) + string("A") + to_string(cow) + string("B");
        return ans;
    }
};
