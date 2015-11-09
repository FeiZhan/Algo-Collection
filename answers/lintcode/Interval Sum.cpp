/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        vector<long long> sum_list;
        long long sum = 0;
        for (size_t i = 0; i < A.size(); ++ i) {
            sum += A[i];
            sum_list.push_back(sum);
        }
        vector<long long> Interval_list;
        for (size_t i = 0; i < queries.size(); ++ i) {
            long long diff = sum_list[queries[i].end] - (queries[i].start >= 1 ? sum_list[queries[i].start - 1] : 0);
            Interval_list.push_back(diff);
        }
        return Interval_list;
    }
};
