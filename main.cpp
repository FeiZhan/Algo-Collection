#include "include/acm_headers.h"
#include "include/leetcode_helper.h"
using namespace std;



int main() {
	Solution s;
	//["What","must","be","shall","be."], 12
	vector<string> words;
	words.push_back(string("What"));
	words.push_back(string("must"));
	words.push_back(string("be"));
	words.push_back(string("shall"));
	words.push_back(string("be."));
	vector<string> ans = s.fullJustify(words, 12);
	for (size_t i = 0; i < ans.size(); ++ i) {
		cout << "|" << ans[i] << "|" << endl;
	}

	return 0;
}








