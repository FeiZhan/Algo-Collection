//@result Submitted a few seconds ago • Score: 20.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0.03s Test Case #5: 0.03s Test Case #6: 0.03s Test Case #7: 0.15s Test Case #8: 0.15s Test Case #9: 0.15s Test Case #10: 0.15s Test Case #11: 0.15s Test Case #12: 0.15s Test Case #13: 0.15s

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long jar_num = 0;
    long long oper_num = 0;
    while (cin >> jar_num >> oper_num) {
        long long sum = 0;
        for (long long i = 0; i < oper_num; ++ i) {
            long long left = 0;
            long long right = 0;
            long long addition = 0;
            cin >> left >> right >> addition;
            sum += (right - left + 1) * addition;
        }
        cout << sum / jar_num << endl;
    }
    return 0;
}
