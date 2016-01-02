class Solution {
public:
    /**
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int> > A) {
        // write your code here
        vector<int> peak;
        size_t left = 1;
        size_t right = A.size() - 2;
        while (left <= right && right < A.size()) {
            size_t middle = (left + right) / 2;
            size_t column = findPeak(A[middle]);
            if (A[middle][column] >= A[middle + 1][column] && A[middle][column] >= A[middle - 1][column]) {
                peak.push_back(middle);
                peak.push_back(column);
                break;
            }
            else if (A[middle][column] < A[middle + 1][column]) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        return peak;
    }
    size_t findPeak(vector<int> &A) {
        size_t peak = 0;
        size_t left = 1;
        size_t right = A.size() - 2;
        while (left <= right && right < A.size()) {
            size_t middle = (left + right) / 2;
            if (A[middle] >= A[middle + 1] && A[middle] >= A[middle - 1]) {
                peak = middle;
                break;
            }
            else if (A[middle] < A[middle + 1]) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        return peak;
    }
};

