//@result Submitted a few seconds ago • Score: 5.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s

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
        int px = 0;
        int py = 0;
        int qx = 0;
        int qy = 0;
        cin >> px >> py >> qx >> qy;
        cout << (qx * 2 - px) << " " << (qy * 2 - py) << endl;
    }
    return 0;
}
