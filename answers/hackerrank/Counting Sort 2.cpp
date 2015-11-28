#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num_num = 0;
    cin >> num_num;
    map<int, int> num_map;
    for (int i = 0; i < num_num; ++ i) {
        int num = 0;
        cin >> num;
        ++ num_map[num];
    }
    for (map<int, int>::iterator it = num_map.begin(); it != num_map.end(); ++ it) {
        for (int i = 0; i < it->second; ++ i) {
            cout << (num_map.begin() == it && 0 == i ? "" : " ") << it->first;
        }
    }
    cout << endl;
    return 0;
}
