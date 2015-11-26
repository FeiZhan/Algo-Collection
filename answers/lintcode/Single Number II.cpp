class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer
	 */
    int singleNumberII(vector<int> &A) {
        // write your code here
        vector<int> bits(32, 0);
        for (size_t i = 0; i < A.size(); ++ i) {
            for (size_t j = 0; j < 32; ++ j) {
                bits[j] += 0 != (A[i] & (1 << j));
            }
        }
        int single = 0;
        for (size_t i = 0; i < bits.size(); ++ i) {
            //cout << "debug " << bits[i] << endl;
            single += (bits[i] % 3) << i;
        }
        return single;
    }
};
