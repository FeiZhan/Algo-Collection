class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> num_list;
        if (n >= 1) {
            for (int i = 1; i <= 9; ++ i) {
                num_list.push_back(i);
            }
            vector<int> prev = numbersByRecursion(n - 1);
            for (size_t i = 0; i < prev.size(); ++ i) {
                for (size_t j = 0; j <= 9; ++ j) {
                    num_list.push_back(prev[i] * 10 + j);
                }
            }
        }
        return num_list;
    }
};
