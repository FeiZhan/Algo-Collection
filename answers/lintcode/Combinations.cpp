class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        // write your code here
		vector<vector<int> > comb_list;
		vector<int> comb;
		combine(1, comb, n, k, comb_list);
		return comb_list;
    }
	void combine(int current, vector<int> &comb, int n, int k, vector<vector<int> > &comb_list) {
		if (comb.size() >= k) {
			comb_list.push_back(comb);
			return;
		}
		for (int i = current; i <= n; ++ i) {
			comb.push_back(i);
			combine(i + 1, comb, n, k, comb_list);
			comb.pop_back();
		}
	}
};
