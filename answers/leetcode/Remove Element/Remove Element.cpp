#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int head = -1, previous = -1, length = n;
        for (int i = 0; i < n; ++ i)
        {
			if (elem == A[i])
			{
				-- length;
				if (head < 0)
				{
					head = i;
					previous = i;
				} else
				{
					A[previous] = i;
					previous = i;
				}
				A[i] = -1;
			}
		}
		int now = head;
		int count = 0;
		// now and next
		while (now >= 0 && A[now] >= 0)
		{
			++ count;
			int next = A[now];
//cout << "test " << count << " " << now << " " << next << endl;
			for (int i = now; i < next - 1 && i < n; ++ i)
			{
				A[i - count + 1] = A[i + 1];
			}
			now = next;
		}
		// consider the last movement
		if (now >= 0)
		{
			for (int i = now; i < n - 1; ++ i)
			{
//cout << "testchange " << i << " " << A[i - count + 1] << " " << A[i + 1] << endl;
				A[i - count] = A[i + 1];
			}
		}
		return length;
    }
    void arrayOut(int A[], int n)
    {
		for (int i = 0; i < n; ++ i)
		{
			cout << A[i] << " ";
		}
		cout << endl;
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
