//@result Accepted Total Runtime: 103 ms 100% test cases passed.

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
		double top(0.0);
		for (size_t i = 0; i < A.size() && i < B.size(); ++ i) {
			top += A[i] * B[i];
		}
		double bottoma(0.0);
		for (size_t i = 0; i < A.size(); ++ i) {
			bottoma += A[i] * A[i];
		}
		double bottomb(0.0);
		for (size_t i = 0; i < B.size(); ++ i) {
			bottomb += B[i] * B[i];
		}
		return (bottoma && bottomb) ? top / sqrt(bottoma) / sqrt(bottomb) : 2.0;
    }
};

