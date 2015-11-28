#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        bool flag = false;
        for (int i = n / 3; i >= 0; -- i) {
            if ((n - i * 3) % 5 == 0) {
                for (int j = 0; j < i * 3; ++ j) {
                    cout << 5;
                }
                for (int j = 0; j + i * 3 < n; ++ j) {
                    cout << 3;
                }
                cout << endl;
                flag = true;
                break;
            }
        }
        if (! flag) {
            cout << -1 << endl;
        }
    }
    return 0;
}
