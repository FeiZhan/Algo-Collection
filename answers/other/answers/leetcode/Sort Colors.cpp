// my own idea, better than leetcode discussion

class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
		int red_end = 0, blue_begin = n;
		for (int i = 0; i < blue_begin; ++ i)
		{
			switch (A[i])
			{
			case 0:
				swap(red_end, i, A);
				++ red_end;
				break;
			case 2:
				swap(blue_begin - 1, i, A);
				-- blue_begin;
				-- i;
				break;
			}
		}
    }
    void swap(int a, int b, int A[])
    {
		int tmp = A[a];
		A[a] = A[b];
		A[b] = tmp;
	}
};
