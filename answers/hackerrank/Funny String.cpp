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
        bool flag = true;
        for (size_t i = 1; i * 2 < text.length(); ++ i) {
            if (abs(text[i - 1] - text[i]) != abs(text[text.length() - i] - text[text.length() - 1 - i])) {
                flag = false;
                break;
            }
        }
        cout << (flag ? "" : "Not ") << "Funny" << endl;
    }
    return 0;
}
