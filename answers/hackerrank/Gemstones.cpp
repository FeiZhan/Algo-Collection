#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int str_num = 0;
    cin >> str_num;
    map<char, int> count_map;
    for (int i = 0; i < str_num; ++ i) {
        string text;
        cin >> text;
        set<char> text_set(text.begin(), text.end());
        for (set<char>::iterator it = text_set.begin(); it != text_set.end(); ++ it) {
            ++ count_map[*it];
        }
    }
    int count = 0;
    for (map<char, int>::iterator it = count_map.begin(); it != count_map.end(); ++ it) {
        if (it->second >= str_num) {
            ++ count;
        }
    }
    cout << count << endl;
    return 0;
}
