class Solution {
public:
	string largestNumber(vector<int> &num) {
		vector<string> num_str;
		for (size_t i = 0; i < num.size(); ++i) {
			string number;
			while (num[i] > 0) {
				number = static_cast<char> (num[i] % 10 + '0') + number;
				num[i] /= 10;
			}
			if (number.length() == 0) {
				number = string("0");
			}
			num_str.push_back(number);
		}
		sort(num_str.begin(), num_str.end(), Solution::compare);
		string ans;
		for (size_t i = 0; i < num_str.size(); ++i) {
			ans += num_str[i];
		}
		while (ans.length() > 1 && '0' == ans[0]) {
			ans.erase(0, 1);
		}
		return ans;
	}
	static bool compare(const string &s0, const string &s1) {
		return s0 + s1 > s1 + s0;
	}
};