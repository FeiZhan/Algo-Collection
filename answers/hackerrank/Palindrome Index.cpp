//@result TLE
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
        for (int i = -1; i < int(text.length()); ++ i) {
            if (-1 == i || text[i] != text[text.length() - 1 - i]) {
                string temp = text;
                if (i >= 0) {
                    temp.erase(i, 1);
                }
                bool flag = true;
                for (size_t j = 0; j * 2 < temp.size(); ++ j) {
                    if (temp[j] != temp[temp.size() - j - 1]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
