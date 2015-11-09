//@result TLE

class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        if (NULL == p) {
            return NULL == s;
        }
        else if ('\0' == p[0]) {
            return '\0' == s[0];
        }
        else if ('*' == p[0]) {
            int star_pos = 0;
            while (p[star_pos] && '*' == p[star_pos]) {
                ++ star_pos;
            }
            int i = -1;
            while (i < 0 || s[i]) {
                ++ i;
                if (isMatch(s + i, p + star_pos)) {
                    return true;
                }
            }
            return false;
        }
        else if ('?' == p[0] || s[0] == p[0]) {
            return isMatch(s + 1, p + 1);
        }
        else {
            return false;
        }
    }
};
