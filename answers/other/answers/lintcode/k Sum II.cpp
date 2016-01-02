//@level Medium 
//@type LintCode Copyright Depth First Search
//@result Accepted Total Runtime: 79 ms 100% test cases passed.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
		ksum.clear();
		vector<int> answer;
		kSumII(0, A, k, target, answer);
		return ksum;
    }
	void kSumII(int current, const vector<int> &A, int k, int target, vector<int> &answer) {
		if (k <= answer.size()) {
			return;
		}
		//cout << "test " << current << " " << k << " " << target << " " << answer.size() << endl;
		for (size_t i = current; i < A.size(); ++ i) {
			if (A[i] == target && answer.size() + 1 == k) {
				ksum.push_back(answer);
				ksum[ksum.size() - 1].push_back(A[i]);
				/*cout << "sum ";
				for (size_t i = 0; i < ksum[ksum.size() - 1].size(); ++ i) {
					cout << ksum[ksum.size() - 1][i] << " ";
				}
				cout << endl;*/
				break;
			}
			else if (A[i] <= target) {
				answer.push_back(A[i]);
				kSumII(i + 1, A, k, target - A[i], answer);
				answer.pop_back();
			}
		}
	}
	vector<vector<int> > ksum;
};

int main() {
	// your code goes here
	Solution s;
	//[1,2,3,4], 2, 5
	vector<int> A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	A.push_back(4);
	vector<vector<int> > ans = s.kSumII(A, 2, 5);
	return 0;
}