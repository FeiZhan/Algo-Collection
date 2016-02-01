//@result Submitted a few seconds ago • Score: 5.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num = 0;
    int sum = 0;
    while (cin >> num) {
        sum += num;
    }
    cout << sum << endl;
    return 0;
}
