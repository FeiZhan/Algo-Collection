//@result Accepted Total Runtime: 160 ms 100% test cases passed.

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
		queue<string> Q;
		Q.push(start);
		Q.push("");
		int res = 1;
		while (!Q.empty()) {
			string str = Q.front();
			Q.pop();
			if ("" != str) {
				int str_len = str.length();
				for (size_t i = 0; i < str_len; ++i) {
					char tmp = str[i];
					for (char c = 'a'; c <= 'z'; ++c) {
						if (c == tmp) {
							continue;
						}
						str[i] = c;
						if (str == end) {
							return res + 1;
						}
						if (dict.end() != dict.find(str)) {
							Q.push(str);
							dict.erase(str);
						}
					}
					str[i] = tmp;
				}
			}
			else if (!Q.empty()) {
				++res;
				Q.push("");
			}
		}
		return 0;
	}
};
