#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int target = 0;
    int num_num = 0;
    cin >> target >> num_num;
    for (int i = 0; i < num_num; ++ i) {
        int num = 0;
        cin >> num;
        if (num == target) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
