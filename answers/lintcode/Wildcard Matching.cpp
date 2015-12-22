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


class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        bool star = false;
        const char *sptr = s;
        const char *pptr = p;
        for (; '\0' != *sptr; ++ sptr, ++ pptr) {
            switch (*pptr) {
            case '?':
                break;
            case '*':
                star = true;
                s = sptr;
                p = pptr;
                while ('*' == *p) {
                    ++ p;
                }
                if ('\0' == *p) {
                    return true;
                }
                sptr = s - 1;
                pptr = p - 1;
                break;
            default:
                if (*sptr != *pptr) {
                    if (! star) {
                        return false;
                    }
                    ++ s;
                    sptr = s - 1;
                    pptr = p - 1;
                }
            }
        }
        while ('*' == *pptr) {
            ++ pptr;
        }
        return '\0' == *pptr;
    }
};
