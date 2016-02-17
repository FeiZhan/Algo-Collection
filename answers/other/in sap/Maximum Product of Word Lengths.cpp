class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bit_list(words.size(), 0);
        for (size_t i = 0; i < words.size(); ++ i) {
            for (size_t j = 0; j < words[i].length(); ++ j) {
                bit_list[i] |= 1 << (words[i][j] - 'a');
            }
        }
        size_t max_product = 0;
        for (size_t i = 0; i < bit_list.size(); ++ i) {
            for (size_t j = i + 1; j < bit_list.size(); ++ j) {
                if (0 == (bit_list[i] & bit_list[j])) {
                    max_product = max(max_product, words[i].length() * words[j].length());
                }
            }
        }
        return max_product;
    }
};