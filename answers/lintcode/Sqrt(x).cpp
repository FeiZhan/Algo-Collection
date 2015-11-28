class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        long long left = 0;
        long long right = x / 2 + 1;
        while (left <= right) {
            long long middle = (left + right) / 2;
            long long square = middle * middle;
            if (square == x) {
                return middle;
            }
            else if (square < x) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        return (left + right) / 2;
    }
};
