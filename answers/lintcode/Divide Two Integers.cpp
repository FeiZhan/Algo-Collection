class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        // Write your code here
        if (0 == divisor) {
            return INT_MAX;
        }
        bool sign = (dividend ^ divisor) >> 31;
        long long _dividend = dividend >= 0 ? dividend : - (long long)(dividend);
        long long _divisor = divisor >= 0 ? divisor : - (long long)(divisor);
        long long divide = 0;
        while (_dividend >= _divisor) {
            long long divisor_temp = _divisor;
            long long ans = 1;
            while (_dividend >= (divisor_temp << 1)) {
                divisor_temp <<= 1;
                ans <<= 1;
            }
            _dividend -= divisor_temp;
            divide += ans;
        }
        //cout << "debug " << divide << endl;
        if ((sign && divide > - (long long)(INT_MIN)) || (! sign && divide > INT_MAX)) {
            return INT_MAX;
        }
        return sign ? - divide : divide;
    }
};
