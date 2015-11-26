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
    string time;
    cin >> time;
    if (time.length() >= 9) {
        if ('1' == time[0] && '2' == time[1] && 'A' == time[8]) {
            time[0] = '0';
            time[1] = '0';
        }
        else if ('P' == time[8] && ! ('1' == time[0] && '2' == time[1])) {
            time[0] += 1;
            time[1] += 2;
            if (time[1] > '9') {
                ++ time[0];
                time[1] -= 10;
            }
        }
    }
    cout << time.substr(0, 8) << endl;
    return 0;
}
