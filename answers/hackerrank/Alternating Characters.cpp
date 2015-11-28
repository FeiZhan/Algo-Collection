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
        size_t current = 0;
        for (size_t i = 1; i < text.length(); ++ i) {
            if (text[i] != text[current]) {
                ++ current;
                text[current] = text[i];
            }
        }
        cout << text.length() - current - 1 << endl;
    }
    return 0;
}
