class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        bool flag = true;
        while (flag) {
            flag = false;
            for (size_t i = 0; i * 2 + 1 < A.size(); ++ i) {
                size_t min_node = i * 2 + 1;
                if (i * 2 + 2 < A.size()) {
                    min_node = A[i * 2 + 1] < A[i * 2 + 2] ? (i * 2 + 1) : (i * 2 + 2);
                }
                if (A[i] > A[min_node]) {
                    flag = true;
                    int temp = A[i];
                    A[i] = A[min_node];
                    A[min_node] = temp;
                }
            }
        }
    }
};
