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
        string text;
        cin >> text;
        int count = 0;
        for (size_t i = 0; i * 2 < text.length(); ++ i) {
            count += abs(text[i] - text[text.length() - 1 - i]);
        }
        cout << count << endl;
    }
    return 0;
}
