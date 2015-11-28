#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int word_num = 0;
    cin >> word_num;
    map<int, int> count_map;
    while (word_num --) {
        int num = 0;
        string text;
        cin >> num >> text;
        ++ count_map[num];
    }
    int count = 0;
    for (int i = 0; i < 100; ++ i) {
        count += count_map[i];
        cout << (i ? " " : "") << count;
    }
    cout << endl;
    return 0;
}
