class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        // Write your code here
        vector<int> code_list;
        code_list.push_back(0);
        for (size_t i = 0; i < n; ++ i) {
            int highest_bit = 1 << i;
            for (size_t j = code_list.size() - 1; j < code_list.size(); -- j) {
                code_list.push_back(highest_bit + code_list[j]);
            }
        }
        return code_list;
    }
};
