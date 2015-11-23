#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int num_num = 0;
    while (cin >> num_num) {
        vector<int> num_list;
        for (int i = 0; i < num_num; ++ i) {
            int num = 0;
            cin >> num;
            num_list.push_back(num);
        }
        bool flag = true;
        for (size_t i = num_list.size() - 1; i < num_list.size(); -- i) {
            if (flag) {
                flag = false;
            }
            else {
                cout << " ";
            }
            cout << num_list[i];
        }
        cout << endl;
    }
    return 0;
}
