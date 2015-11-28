#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string text;
    set<char> char_list;
    while (cin >> text) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        for (size_t i = 0; i < text.length(); ++ i) {
            if (text[i] >= 'a' && text[i] <= 'z') {
                char_list.insert(text[i]);
            }
        }
    }
    cout << (char_list.size() >= 26 ? "" : "not ") << "pangram" << endl;
    return 0;
}
