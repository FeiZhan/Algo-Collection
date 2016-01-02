#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int first_num = 0;
    cin >> first_num;
    map<int, int> first_list;
    for (int i = 0; i < first_num; ++ i) {
        int num = 0;
        cin >> num;
        ++ first_list[num];
    }
    int second_num = 0;
    cin >> second_num;
    for (int i = 0; i < second_num; ++ i) {
        int num = 0;
        cin >> num;
        -- first_list[num];
    }
    bool flag = true;
    for (map<int, int>::iterator it = first_list.begin(); it != first_list.end(); ++ it) {
        if (it->second) {
            if (flag) {
                flag = false;
            }
            else {
                cout << " ";
            }
            cout << it->first;
        }
    }
    cout << endl;
    return 0;
}
