#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
    }
};
int main()
{
	Solution s;
	//[1], 1
	int A[1] = {1};
	cout << s.removeElement(A, 1, 1) << endl;
	s.arrayOut(A, 1);
	//[4,5], 4
	int B[2] = {4, 5};
	cout << s.removeElement(B, 2, 4) << endl;
	s.arrayOut(B, 2);
	return 0;
}
