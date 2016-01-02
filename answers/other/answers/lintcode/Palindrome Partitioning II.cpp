class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        // write your code here
        vector<int> min_cut(s.length(), INT_MAX);
        vector<vector<bool> > palin(s.length(), vector<bool> (s.length(), false));
        for (size_t i = 0; i < s.length(); ++ i) {
            min_cut[0] = 0;
            for (size_t j = 0; i + j < s.length(); ++ j) {
                if (0 == i) {
                    palin[i][j] = true;
                }
                else if (1 == i) {
                    palin[i][j] = s[j] == s[i + j];
                }
                else {
                    palin[i][j] = palin[i - 2][j + 1] && s[j] == s[i + j];
                }
            }
        }
        min_cut[0] = 0;
        for (size_t i = 0; i < s.length(); ++ i) {
            for (size_t j = i; j < s.length(); ++ j) {
                if (palin[j - i][i]) {
                    min_cut[j] = min(min_cut[j], (i > 0 ? min_cut[i - 1] + 1 : 0));
                }
            }
        }
        return min_cut[s.length() - 1];
    }
};
