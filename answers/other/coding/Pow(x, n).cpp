class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        // Write your code here
        map<int, double> pow_map;
        myPow(x, abs(n), pow_map);
        return n >= 0 ? pow_map[abs(n)] : 1 / pow_map[abs(n)];
    }
    void myPow(double x, int n, map<int, double> &pow_map) {
        if (pow_map.end() == pow_map.find(n)) {
            double answer = 0.0;
            if (0 == n) {
                answer = 1.0;
            }
            else if (1 == n) {
                answer = x;
            }
            else {
                myPow(x, n / 2, pow_map);
                answer = pow_map[n / 2] * pow_map[n / 2] * (n % 2 ? x : 1);
            }
            pow_map.insert(make_pair(n, answer));
        }
    }
};