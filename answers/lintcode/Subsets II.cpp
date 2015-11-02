class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        // write your code here
        vector<int> num_list(S.begin(), S.end());
    	sort(num_list.begin(), num_list.end());
    	subset_list.clear();
    	std::vector<int> subset;
    	subsetsWithDup(0, subset, num_list);
    	return subset_list;
    }
    void subsetsWithDup(size_t current, std::vector<int> &subset, const vector<int> &num_list) {
    	subset_list.push_back(subset);
    	for (size_t i = current; i < num_list.size(); ++ i) {
    		subset.push_back(num_list[i]);
    		subsetsWithDup(i + 1, subset, num_list);
    		subset.pop_back();
    		while (i + 1 < num_list.size() && num_list[i] == num_list[i + 1]) {
    			++ i;
    		}
    	}
    }
    std::vector<std::vector<int> > subset_list;
};

