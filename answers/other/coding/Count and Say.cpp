class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        // Write your code here
        string num("1");
        for (int i = 1; i < n; ++ i) {
            string temp;
            int count = 1;
            for (size_t j = 0; j < num.size(); ++ j) {
                if (num.size() - 1 == j || num[j] != num[j + 1]) {
                    temp += static_cast<char> ('0' + count);
                    temp += num[j];
                    count = 1;
                }
                else {
                    ++ count;
                }
            }
            num = temp;
        }
        return num;
    }
};