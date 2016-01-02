class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here
        int count = 0;
        while (num) {
            num &= num - 1;
            ++ count;
        }
        return count;
    }
};
