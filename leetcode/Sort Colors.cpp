#include <iostream>
using namespace std;
void printArray(int A[], int n)
{
	for (int i = 0; i < n; ++ i)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}
class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
		int red_end = 0, blue_begin = n - 1;
		for (int i = 0; i <= blue_begin; ++ i)
		{
cout << "testing " << i << endl;
			switch (A[i])
			{
			case 0:
				if (i > red_end)
				{
					swap(A, red_end, i);
					++ red_end;
					++ i;
				}
				break;
			case 2:
				if (i < blue_begin)
				{
					swap(A, blue_begin, i);
					-- blue_begin;
					-- i;
				}
				break;
			}
cout << "result " << red_end << " " << blue_begin << endl;
printArray(A, n);
		}
    }
    void swap(int A[], int a, int b)
    {
		int tmp = A[a];
		A[a] = A[b];
		A[b] = tmp;
	}
};
int main()
{
	Solution s;
	//[2,0]
	int A[2] = {2, 0};
cout << "begin " << endl;
printArray(A, 2);
	s.sortColors(A, 2);
	printArray(A, 2);
	//[0,2,1]
	int B[3] = {0, 2, 1};
cout << "begin " << endl;
printArray(B, 3);
	s.sortColors(B, 3);
	printArray(B, 3);
	//[1,2,0]
	int C[3] = {1, 2, 0};
cout << "begin " << endl;
printArray(C, 3);
	s.sortColors(C, 3);
	printArray(C, 3);
	//[0,1,0]
	int D[3] = {0, 1, 0};
cout << "begin " << endl;
printArray(D, 3);
	s.sortColors(D, 3);
	printArray(D, 3);
	return 0;
}
