#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string binaryRepresentation(string n) {
        // wirte your code here
        vector<int> integer;
        vector<int> decimal;
        bool flag = false;
        bool start_flag = false;
        for (size_t i = 0; i < n.length(); ++ i) {
            if ('.' == n[i]) {
                flag = true;
                start_flag = false;
                continue;
            }
            if (! start_flag && '0' != n[i]) {
                start_flag = true;
            }
            if (flag) {
                decimal.push_back(static_cast<int> (n[i] - '0'));
            }
            else {
                if (! start_flag) {
                    continue;
                }
                integer.push_back(static_cast<int> (n[i] - '0'));
            }
        }
        if (flag && ! start_flag) {
            decimal.clear();
        }
        string binary;
        flag = true;
        while (flag) {
            flag = false;
            int carry = 0;
            for (size_t i = 0; i < integer.size(); ++ i) {
                if (integer[i] > 0) {
                    flag = true;
                }
                integer[i] += 10 * carry;
                carry = integer[i] % 2;
                integer[i] /= 2;
            }
            if (flag) {
                binary = static_cast<char> (carry + '0') + binary;
            }
        }
        flag = decimal.size() > 0;
        if (0 == binary.size()) {
            binary += '0';
        }
        if (flag) {
            binary += '.';
        }
        int count = 0;
        while (flag) {
            flag = false;
            int carry = 0;
            for (size_t i = decimal.size() - 1; i < decimal.size(); -- i) {
                if (decimal[i] > 0) {
                    flag = true;
                }
                //cout << "decimal " << i << " " << decimal[i] << endl;
                decimal[i] = decimal[i] * 2 + carry;
                carry = decimal[i] / 10;
                decimal[i] %= 10;
            }
            if (flag) {
                ++ count;
                binary += static_cast<char> (carry + '0');
                //cout << "test " << binary << endl;
                if (count > 32) {
                    return string("ERROR");
                }
            }
        }
        return binary;
    }
};

int main() {
	// your code goes here
    Solution s;
    cout << s.binaryRepresentation(string("6.125")) << endl;
	return 0;
}
