class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
		size_t remain = 0;
		for (size_t i = 0; i < A.size(); ++ i) {
			if (A[i] != elem) {
				A[remain] = A[i];
				++ remain;
			}
		}
		return remain;
    }
};
