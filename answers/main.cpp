class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        // write you code here
        unordered_map<int, int> num_map;
        bool flag = true;
        while (flag) {
            flag = false;
            for (size_t i = 0; i < num.size(); ++ i) {
                if (num_map.end() == num_map.find(num[i])) {
                    num_map.insert(make_pair(num[i], 1));
                    flag = true;
                }
                if (num_map.end() != num_map.find(num[i] - 1) && num_map[num[i] - 1] + 1 > num_map[num[i]]) {
                    num_map[num[i]] = num_map[num[i] - 1] + 1;
                    flag = true;
                }
                if (num_map.end() != num_map.find(num[i] + 1) && num_map[num[i]] + 1 > num_map[num[i] + 1]) {
                    num_map[num[i] + 1] = num_map[num[i]] + 1;
                    flag = true;
                }
            }
        }
        int longest = 0;
        for (unordered_map<int, int>::iterator it = num_map.begin(); it != num_map.end(); ++ it) {
            longest = max(longest, it->second);
        }
        return longest;
    }
};
