class Solution {
public:
    /**
     * @param ratings Children's ratings
     * @return the minimum candies you must give
     */
    int candy(vector<int>& ratings) {
        // Write your code here
        vector<int> candy_list(ratings.size(), 0);
        for (size_t i = 0; i < ratings.size(); ++ i) {
            candy_list[i] = (i > 0 && ratings[i] > ratings[i - 1]) ? candy_list[i - 1] + 1 : 1;
        }
        for (size_t i = ratings.size() - 1; i < ratings.size(); -- i) {
            candy_list[i] = max(candy_list[i], ((i + 1 < ratings.size() && ratings[i] > ratings[i + 1]) ? candy_list[i + 1] + 1 : 1));
        }
        return std::accumulate(candy_list.begin(), candy_list.end(), 0);
    }
};
