#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int case_num = 0;
    cin >> case_num;
    while (case_num --) {
        string text;
        cin >> text;
        if (text.length() % 2) {
            cout << -1 << endl;
            continue;
        }
        map<char, int> char_map;
        for (size_t i = 0; i * 2 < text.length(); ++ i) {
            if (char_map.end() == char_map.find(text[i])) {
                //char_map.insert(make_pair(text[i], 0));
            }
            ++ char_map[text[i]];
        }
        for (size_t i = text.length() / 2; i < text.length(); ++ i) {
            if (char_map.end() == char_map.find(text[i])) {
                //char_map.insert(make_pair(text[i], 0));
            }
            -- char_map[text[i]];
        }
        int change_num = 0;
        for (map<char, int>::iterator it = char_map.begin(); it != char_map.end(); ++ it) {
            change_num += abs(it->second);
        }
        cout << change_num / 2 << endl;
    }
    return 0;
}
