class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        // Write your code here
        set<int> square_set;
        while (true) {
            int sum = 0;
            while (n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            if (1 == sum) {
                return true;
            }
            else if (square_set.end() != square_set.find(sum)) {
                return false;
            }
            else {
                square_set.insert(sum);
            }
            n = sum;
        }
    }
};