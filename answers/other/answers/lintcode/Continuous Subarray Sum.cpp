class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        int local = 0;
        int global = INT_MIN;
        vector<int> local_range(2, 0);
        vector<int> global_range(2, 0);
        for (size_t i = 0; i < A.size(); ++ i) {
            if (local + A[i] >= A[i]) {
                local += A[i];
                local_range[1] = i;
            }
            else {
                local = A[i];
                local_range[0] = i;
                local_range[1] = i;
            }
            if (local > global) {
                global = local;
                global_range[0] = local_range[0];
                global_range[1] = local_range[1];
            }
        }
        return global_range;
    }
};
