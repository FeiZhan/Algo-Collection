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
        size_t i = 0;
        for (i = text.length() - 2; i < text.length(); -- i) {
            if (text[i] < text[i + 1]) {
                break;
            }
        }
        //cout << "debug " << i << " " << text << endl;
        if (i < text.length() - 1) {
            size_t target = i + 1;
            for (size_t j = i + 1; j < text.length(); ++ j) {
                if (text[j] > text[i] && text[j] < text[target]) {
                    target = j;
                }
            }
            char temp = text[i];
            text[i] = text[target];
            text[target] = temp;
            sort(text.begin() + i + 1, text.end());
            cout << text << endl;
        }
        else {
            cout << "no answer" << endl;
        }
    }
    return 0;
}
