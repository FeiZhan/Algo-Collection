//@result TLE

class Solution {
public:
    vector<string> addOperators(string num, int target) {
		exp_list.clear();
		addOperators(0, num, target, string ());
		return exp_list;
	}
    void addOperators(const long long &current, const string &num, const long long &target, string exp) {
		if (current + 1 >= num.length()) {
			long long right_num(atoll(num.substr(current).c_str()));
			if (current + 1 == num.length() && right_num == target) {
				exp_list.push_back(exp + num.substr(current));
			}
		}
		else {
			long long left_num(0);
			for (long long i = current; i < num.length(); ++ i) {
				left_num = left_num * 10 + static_cast<long long> (num[i] - '0');
				addOperators(i + 1, num, target - left_num, exp + to_string(left_num) + "+");
				addOperators(i + 1, num, left_num - target, exp + to_string(left_num) + "-");
				if (0 != left_num) {
					addOperators(i + 1, num, target / left_num, exp + to_string(left_num) + "*");
				}
			}
		}
    }
	vector<string> exp_list;
};