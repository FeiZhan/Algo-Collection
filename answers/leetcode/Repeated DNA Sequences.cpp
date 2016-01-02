//@result Status: Accepted Runtime: 210 ms Submitted: 10 months, 2 weeks ago You are here! Your runtime beats 23.59% of cpp submissions.

#include "include/acm_headers.h"
#include "include/leetcode_helper.h"
using namespace std;

class Solution {
public:
	Solution (void) {
		DNA_MAP['A'] = 0;
		DNA_MAP['C'] = 1;
		DNA_MAP['G'] = 2;
		DNA_MAP['T'] = 3;
		NUM_MAP[0] = 'A';
		NUM_MAP[1] = 'C';
		NUM_MAP[2] = 'G';
		NUM_MAP[3] = 'T';
	}
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> ans_list;
		if (s.length() < 10) {
			return ans_list;
		}
		vector<int> bit_list;
		for (size_t i = 0; i < s.length(); ++ i) {
			bit_list.push_back(DNA_MAP[s[i]]);
			//cout << s[i] << " " << bit_list[bit_list.size() - 1] << endl;
		}
		int num = 0;
		for (size_t i = 0; i < 9 && i < bit_list.size(); ++ i) {
			num = (num << 2) + bit_list[i];
		}
		//cout << num << " " << dnaStr(num) << endl;
		map<int, unsigned> seq_map;
		for (size_t i = 9; i < s.length(); ++ i) {
			num = (num << 2) % 1048576 + bit_list[i];
			++ seq_map[num];
		}
		for (map<int, unsigned>::iterator it = seq_map.begin(); it != seq_map.end(); ++ it) {
			if (it->second > 1) {
				ans_list.push_back(dnaStr(it->first));
				//cout << ans_list[ans_list.size() - 1] << " " << it->second << endl;
			}
		}
		return ans_list;
	}
	string dnaStr(int dna_num) {
		string ans;
		for (size_t i = 0; i < 10; ++ i) {
			ans += NUM_MAP[dna_num % 4];
			dna_num /= 4;
		}
		std::reverse(ans.begin(), ans.end());
		return ans;

	}
	map<char, int> DNA_MAP;
	map<char, int> NUM_MAP;
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<string> ans = s.findRepeatedDnaSequences(string("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"));
	for (size_t i = 0; i < ans.size(); ++ i) {
		cout << ans[i] << ", ";
	}
	cout << endl;
	return 0;
}
