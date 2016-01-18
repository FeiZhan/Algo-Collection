//@result Accepted Total Runtime: 18 ms 100% test cases passed.

class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        int count = 0;
        int base = 1;
        while (n / base > 0) {
            int current = (n / base) % 10;
            int low = n - (n / base) * base;
            int high = n / base / 10;
            count += high * base;
            if (current == k) {
                count += low + 1;
            }
            // if k == 0
            else if (current > k && (k != 0 || high != 0)) {
                count += base;
            }
            base *= 10;
        }
        // note
        if (0 == k && 0 == n) {
            ++ count;
        }
        return count;
    }
};
