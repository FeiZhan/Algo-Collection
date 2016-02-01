//@result Submitted a few seconds ago • Score: 100.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s Test Case #6: 0s Test Case #7: 0s Test Case #8: 0s Test Case #9: 0s Test Case #10: 0s Test Case #11: 0s Test Case #12: 0s Test Case #13: 0s Test Case #14: 0s Test Case #15: 0s

#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string input;
    while (cin >> input) {
        unordered_map<char, int> char_map;
        for (size_t i = 0; i < input.length(); ++ i) {
            ++ char_map[input[i]];
        }
        int max_value = 0;
        int max_count = 0;
        unordered_map<int, int> count_map;
        for (unordered_map<char, int>::iterator it = char_map.begin(); it != char_map.end(); ++ it) {
            ++ count_map[it->second];
            if (max_count < count_map[it->second]) {
                max_count = count_map[it->second];
                max_value = it->second;
            }
        }
        int count = 0;
        for (unordered_map<char, int>::iterator it = char_map.begin(); it != char_map.end(); ++ it) {
            count += min(it->second, abs(it->second - max_value));
            //cout << "debug " << it->second << " " << max_value << " " << count << endl;
        }
        cout << (count <= 1 ? "YES" : "NO") << endl;
    }
    return 0;
}
