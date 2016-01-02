class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        long long ans = pow(a, b, n);
        return (int)(ans);
    }
    long long pow(int a, int b, int n) {
        if (0 == a) {
            return a;
        }
        else if (0 == n) {
            return 1 % b;
        }
        else if (1 == n) {
            return a % b;
        }
        long long ans = pow(a, b, n / 2);
        ans = (ans * ans) % b;
        if (n % 2) {
            ans *= pow(a, b, 1);
        }
        return ans % b;
    }
};
