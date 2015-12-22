class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        // write you code here
        sort(num.begin(), num.end());
        map<int, int> num_map;
        int longest = 0;
        for (size_t i = 0; i < num.size(); ++ i) {
            num_map[num[i]] = num_map[num[i] - 1] + 1;
            longest = max(longest, num_map[num[i]]);
        }
        return longest;
    }
};
