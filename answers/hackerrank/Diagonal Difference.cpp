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
    int n;
    cin >> n;
    vector< vector<int> > a(n,vector<int>(n));
    int diagonal[2] = {0, 0};
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
          if (a_i == a_j) {
              diagonal[0] += a[a_i][a_j];
          }
          if (a_i + a_j == n - 1) {
              diagonal[1] += a[a_i][a_j];
          }
       }
    }
    cout << abs(diagonal[0] - diagonal[1]) << endl;
    return 0;
}
