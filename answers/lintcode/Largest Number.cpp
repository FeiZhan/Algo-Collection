//@level Medium 
//@type LintCode Copyright Sort
//@result Accepted Total Runtime: 18 ms 100% test cases passed.

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        // write your code here
		vector<string> num1(num.size());
		transform(num.begin(), num.end(), num1.begin(), [] (int x) {
			return to_string(x);
		});
		sort(num1.begin(), num1.end(), [] (const string &x, const string &y) {
			return x + y > y + x;
		});
		string ans = accumulate(num1.begin(), num1.end(), string(""));
		ans.erase(0, ans.find_first_not_of('0'));
		return ans.length() ? ans : string("0");
    }
};

int main() {
	// your code goes here
	Solution s;
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	num.push_back(4);
	num.push_back(5);
	s.largestNumber(num);
	return 0;
}