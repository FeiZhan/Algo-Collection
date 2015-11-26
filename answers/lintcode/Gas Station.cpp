class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        int start = 0;
        int start_sum = 0;
        int sum = 0;
        for (size_t i = 0; i < gas.size(); ++ i) {
            sum += gas[i] - cost[i];
            start_sum += gas[i] - cost[i];
            if (start_sum < 0) {
                start = i + 1;
                start_sum = 0;
            }
        }
        return sum >= 0 ? start : -1;
    }
};
