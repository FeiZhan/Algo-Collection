class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (size_t i = 0; i < num.length(); ++ i) {
            if (isAdditiveNumber(0, i + 1, num, 0)) {
                return true;
            }
        }
        return false;
    }
    bool isAdditiveNumber(size_t begin, size_t current, const string &num, int level) {
        cout << "debug " << begin << " " << current << endl;
        if (current + 1 >= num.length() && level > 0) {
            return true;
        }
        for (size_t i = current; i < num.length(); ++ i) {
            string sum;
            size_t j = current - 1;
            size_t k = i;
            int carry = 0;
            while ((j >= begin && j < num.length()) || (k >= current && k < num.length()) || carry) {
                int digit = carry;
                if (j >= begin && j < num.length()) {
                    digit += num[j] - '0';
                }
                if (k >= current && k < num.length()) {
                    digit += num[k] - '0';
                }
                carry = digit / 10;
                sum = static_cast<char> (digit % 10 + '0') + sum;
                -- j;
                -- k;
            }
            cout << "check " << sum << " " << num.substr(i + 1, sum.length()) << endl;
            if (sum == num.substr(i + 1, sum.length()) && (i + 1 + sum.length() >= num.length() || isAdditiveNumber(current, i + 1, num, level + 1))) {
                return true;
            }
        }
        return false;
    }
};