//@result Submitted a few seconds ago • Score: 25.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s Test Case #6: 0s Test Case #7: 0s Test Case #8: 0s Test Case #9: 0s Test Case #10: 0s

#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int str_num = 0;
    while (cin >> str_num) {
        unordered_map<string, int> str_map;
        for (int i = 0; i < str_num; ++ i) {
            string input;
            cin >> input;
            ++ str_map[input];
        }
        int query_num = 0;
        cin >> query_num;
        for (int i = 0; i < query_num; ++ i) {
            string query;
            cin >> query;
            cout << str_map[query] << endl;
        }
    }
    return 0;
}
