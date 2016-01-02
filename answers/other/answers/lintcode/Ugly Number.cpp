class Solution {
public:
	Solution(void) {
		set<long long> ugly_set;
		ugly_set.insert(1);
		set<long long>::iterator it = ugly_set.begin();
		while (ugly_set.size() < 2000) {
			ugly_set.insert((*it) * 3);
			ugly_set.insert((*it) * 5);
			ugly_set.insert((*it) * 7);
			++ it;
		}
		ugly_list.resize(ugly_set.size());
		copy(ugly_set.begin(), ugly_set.end(), ugly_list.begin());
		/*for (size_t i = 0; i < ugly_list.size(); ++ i) {
			cout << "test " << i << " " << ugly_list[i] << endl;
		}*/
	}
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
	//int nthUglyNumber(int k) {
        // write your code here
        return ugly_list[k];
    }
    vector<long long> ugly_list;
};
