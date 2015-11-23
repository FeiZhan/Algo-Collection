class Solution {
public:
    /**
     * @param A an integer array
     * @param start an integer
     * @param end an integer
     * @return the number of possible answer
     */
    int subarraySumII(vector<int>& A, int start, int end) {
        // Write your code here
        int sum_num = 0;
        int sum = 0;
        multimap<int, size_t> sum_map;
        sum_map.insert(make_pair(0, 0));
        for (size_t i = 0; i < A.size(); ++ i) {
            sum += A[i];
            multimap<int, size_t>::iterator lower = sum_map.lower_bound(sum - end);
            multimap<int, size_t>::iterator upper = sum_map.upper_bound(sum - start);
            //cout << "debug " << i << " " << A[i] << " " << lower->first << " " << upper->first << endl;
            sum_num += distance(lower, upper);
            sum_map.insert(make_pair(sum, i));
        }
        return sum_num;
    }
};
