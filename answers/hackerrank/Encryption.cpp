//@result Submitted a few seconds ago • Score: 30.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s Test Case #6: 0s Test Case #7: 0s Test Case #8: 0s Test Case #9: 0s Test Case #10: 0s Test Case #11: 0s Test Case #12: 0s

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    string s;
    cin >> s;
    for (size_t i = 0; i < s.length(); ++ i) {
        if (' ' == s[i]) {
            s.erase(i, 1);
            -- i;
        }
    }
    // should be rounding up
    size_t row_num = int(sqrt(s.length()) + 0.5);
    // easy ceiling function
    size_t column_num = (s.length() + row_num - 1) / row_num;
    string encrypted;
    for (size_t i = 0; i < column_num; ++ i) {
        if (i > 0) {
            encrypted += " ";
        }
        for (size_t j = 0; j < row_num && i + j * column_num < s.length(); ++ j) {
            encrypted += s[i + j * column_num];
        }
    }
    cout << encrypted << endl;

    return 0;
}
