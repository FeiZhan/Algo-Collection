//@type string
//@level medium
//@result Submitted a few seconds ago • Score: 30.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0.02s Test Case #4: 0.06s Test Case #5: 0.06s

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <string>

string TwoStrings(string &a, string &b) {
	vector<bool> letter_list(26, false);
	for (size_t i = 0; i < a.length(); ++ i) {
		letter_list[static_cast<size_t> (a[i] - 'a')] = true;
	}
	for (size_t i = 0; i < b.length(); ++ i) {
		if (letter_list[static_cast<size_t> (b[i] - 'a')]) {
			return string("YES");
		}
	}
	return string("NO");
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int case_num(0);
	cin >> case_num;
	while (case_num --) {
		string a, b;
		cin >> a >> b;
		cout << TwoStrings(a, b) << endl;
	}
    return 0;
}