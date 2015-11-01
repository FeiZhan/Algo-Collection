//@level Medium 
//@type String Two Pointers LintCode Copyright Sort
//@result Accepted Total Runtime: 17 ms 100% test cases passed.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
		size_t lower(0);
		size_t upper(letters.size() - 1);
		while (lower < upper && upper < letters.size()) {
			if (! (letters[lower] >= 'a' && letters[lower] <= 'z') && ! (letters[upper] >= 'A' && letters[upper] <= 'A')) {
				char temp = letters[lower];
				letters[lower] = letters[upper];
				letters[upper] = temp;
			}
			while (lower < letters.size() && letters[lower] >= 'a' && letters[lower] <= 'z') {
				++ lower;
			}
			while (upper < letters.size() && letters[upper] >= 'A' && letters[upper] <= 'Z') {
				-- upper;
			}
		}
    }
};

int main() {
	// your code goes here
	Solution s;
	string letters("DERLKAJKFKLAJFKAKLFJKLJFa");
	s.sortLetters(letters);
	cout << letters << endl;
	return 0;
}