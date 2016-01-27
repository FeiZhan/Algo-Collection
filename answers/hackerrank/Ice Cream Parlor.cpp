//@result Submitted a few seconds ago • Score: 30.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0.01s

#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int case_num = 0;
    cin >> case_num;
    while (case_num --) {
        int money = 0;
        int cost_num = 0;
        cin >> money >> cost_num;
        unordered_map<int, int> cost_map;
        for (int i = 0; i < cost_num; ++ i) {
            int cost = 0;
            cin >> cost;
            if (cost_map.end() != cost_map.find(money - cost)) {
                cout << cost_map[money - cost] + 1 << " " << i + 1 << endl;
            }
            cost_map.insert(make_pair(cost, i));
        }
    }
    return 0;
}
