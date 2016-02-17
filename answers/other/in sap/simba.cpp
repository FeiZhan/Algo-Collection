// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <cassert>
int solution(int N) {
    // write your code in C++11
    assert(N >= 0);
    int count = 0;
    int length = 1;
    while (N >= length) {
        int left = N / (length * 10);
        int current = N / length % 10;
        int right = N % length;
        count += left * length;
        if (current >= 2) {
            count += length;
        }
        else if (1 == current) {
            count += right + 1;
        }
        length *= 10;
    }
    return count;
}
// time complexity: O(k) (k is the number of digits in N)
// space complexity: O(1)



int solution(vector<int>& A, int X) {
    int N = A.size();
    if (N == 0) {
        return -1;
    }
    int l = 0;
    int r = N - 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (A[m] > X) {
            r = m - 1;
        } else if (A[m] < X) {
            l = m + 1;
        } else {l = m; break;}
    }
    if (A[l] == X) {
        return l;
    }
    return -1;
}