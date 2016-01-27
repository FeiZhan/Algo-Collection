//@result Submitted a few seconds ago • Score: 30.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s Test Case #6: 0.01s Test Case #7: 0.01s Test Case #8: 0.01s Test Case #9: 0.03s Test Case #10: 0.03s Test Case #11: 0.02s Test Case #12: 0.02s Test Case #13: 0.03s Test Case #14: 0s Test Case #15: 0s

#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long num_num = 0;
    while (cin >> num_num) {
        vector<long long> num_list(num_num, 0);
        long long pmean = 0;
        long long sum = 0;
        for (long long i = 0; i < num_list.size(); ++ i) {
            cin >> num_list[i];
            sum += num_list[i];
            pmean += (i + 1) * num_list[i];
        }
        long long max_sum = pmean;
        for (long long i = 0; i < num_list.size(); ++ i) {
            pmean += - sum + num_list[i] * num_list.size();
            max_sum = max(max_sum, pmean);
        }
        cout << max_sum << endl;
    }
    return 0;
}
