#include <cmath>
#include <cstdio>
#include <climits>
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
        cin >> num_num;
        int max_num = INT_MIN;
        int max_non_cont = 0;
        int local = INT_MIN / 10;
        int global = INT_MIN / 10;
        for (int i = 0; i < num_num; ++ i) {
            int num = 0;
            cin >> num;
            max_num = max(max_num, num);
            local = max(local + num, num);
            global = max(global, local);
            max_non_cont += num > 0 ? num : 0;
        }
        cout << global << " " << (max_num < 0 ? max_num : max_non_cont) << endl;
    }
    return 0;
}
