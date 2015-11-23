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
        cin >> num_num;
        vector<int> num_list;
        int sum = 0;
        for (int i = 0; i < num_num; ++ i) {
            int num = 0;
            cin >> num;
            sum += num;
            num_list.push_back(num);
        }
        int current = 0;
        bool flag = false;
        for (size_t i = 0; i < num_list.size(); ++ i) {
            if (current * 2 + num_list[i] == sum) {
                flag = true;
                break;
            }
            current += num_list[i];
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
