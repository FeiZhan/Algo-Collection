//@result Submitted a few seconds ago • Score: 10.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    const string NUMBER[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "Greater than 9"};
    int begin = 0;
    int end = 0;
    while (cin >> begin >> end) {
        for (int i = begin; i <= end; ++ i) {
            if (i > 9) {
                cout << (i % 2 ? "odd" : "even") << endl;
            } else {
                cout << NUMBER[i] << endl;
            }
        }
    }
   return 0;
}
