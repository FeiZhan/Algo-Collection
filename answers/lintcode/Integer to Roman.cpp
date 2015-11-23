class Solution {
public:
    /**
     * @param n The integer
     * @return Roman representation
     */
    string intToRoman(int n) {
        // Write your code here
        string roman;
        for (size_t i = 0; n > 0; ++ i) {
            while (n >= value[i]) {
                n -= value[i];
                roman += symbol[i];
            }
        }
        return roman;
    }
    static const string symbol[];
    static const int value[];
};
const string Solution::symbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
const int Solution::value[]=    {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1};