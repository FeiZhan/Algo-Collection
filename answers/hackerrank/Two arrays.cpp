//@result Submitted a few seconds ago • Score: 40.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s Test Case #6: 0s Test Case #7: 0s Test Case #8: 0s Test Case #9: 0s

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int case_num = 0;
    cin >> case_num;
    while (case_num --) {
        int num_num = 0;
        int target = 0;
        cin >> num_num >> target;
        vector<int> num0_list(num_num, 0);
        for (size_t i = 0; i < num0_list.size(); ++ i) {
            cin >> num0_list[i];
        }
        sort(num0_list.begin(), num0_list.end());
        vector<int> num1_list(num_num, 0);
        for (size_t i = 0; i < num1_list.size(); ++ i) {
            cin >> num1_list[i];
        }
        sort(num1_list.begin(), num1_list.end(), greater<int> ());
        bool flag = true;
        for (size_t i = 0; i < num0_list.size(); ++ i) {
            if (num0_list[i] + num1_list[i] < target) {
                flag = false;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
