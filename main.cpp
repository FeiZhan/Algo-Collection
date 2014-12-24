#include "include/acm_headers.h"
#include "include/leetcode_helper.h"
using namespace std;

class Solution {
public:
	string minWindow(string S, string T) {
		std::map<char, int> target_map;
		for (size_t i = 0; i < T.length(); ++ i) {
			++ target_map[T[i]];
		}
		std::map<char, int> source_map;
		int source_count = 0;
		size_t source_start = UINT_MAX;
		int min_len = INT_MAX;
		size_t min_start = 0;
		for (size_t i = 0; i < S.length(); ++ i) {
			if (target_map.end() == target_map.find(S[i])) {
				continue;
			}
			++ source_map[S[i]];
			++ source_count;
			if (UINT_MAX == source_start) {
				i = source_start;
			}
			if (T.length() == source_count) {
				if (i - min_start < min_len) {
					bool flag = true;
					for (std::map<char, int>::iterator it = source_map.begin(); it != source_map.end(); ++ it) {
						if (it->second != target_map[it->first]) {
							flag = false;
							break;
						}
					}
					if (flag) {
						min_len = i - min_start;
						min_start = source_start;
					}
				}
				int remove_count = 0;
				for (size_t j = source_start; j <= i; ++ j) {
					if (source_map.end() == source_map.find(S[j]) || 0 == source_map[S[j]]) {
						continue;
					}
					if (0 == remove_count) {
						-- source_map[S[j]];
						++ remove_count;
					}
					else if (1 == remove_count) {
						source_start = j;
						break;
					}
				}
			}
		}
		if (INT_MAX == min_len || UINT_MAX == source_start) {
			return string("");
		}
		return S.substr(min_start, min_len + 1);
	}
};

int main() {
	Solution s;
	string ans = s.minWindow(string("ab"), string("b"));
	cout << ans << endl;

	return 0;
}








