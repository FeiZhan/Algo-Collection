//@result Submitted a few seconds ago • Score: 10.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s Test Case #6: 0s Test Case #7: 0s Test Case #8: 0s Test Case #9: 0s Test Case #10: 0s Test Case #11: 0s

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    const string NUMBER[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "Greater than 9"};
    int num = 0;
    while (cin >> num) {
        if (num > 9) {
            num = 10;
        }
        cout << NUMBER[num] << endl;
    }
   return 0;
}
