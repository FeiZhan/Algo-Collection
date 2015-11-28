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
    int d1;
    int m1;
    int y1;
    cin >> d1 >> m1 >> y1;
    int d2;
    int m2;
    int y2;
    cin >> d2 >> m2 >> y2;
    int fine = 0;
    if (y1 > y2) {
        fine = 10000;
    }
    else if (y1 == y2 && m1 > m2) {
        fine = 500 * (m1 - m2);
    }
    else if (y1 == y2 && m1 == m2 && d1 > d2) {
        fine = 15 * (d1 - d2);
    }
    cout << fine << endl;
    return 0;
}
