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
    vector<string> grid(n);
    for(int grid_i = 0;grid_i < n;grid_i++){
       cin >> grid[grid_i];
    }
    for (size_t i = 1; i + 1 < grid.size(); ++ i) {
        for (size_t j = 1; j + 1 < grid[i].length(); ++ j) {
            if (grid[i][j] > grid[i - 1][j] && grid[i][j] > grid[i + 1][j] && grid[i][j] > grid[i][j - 1] && grid[i][j] > grid[i][j + 1]) {
                grid[i][j] = 'X';
            }
        }
    }
    for (size_t i = 0; i < grid.size(); ++ i) {
        cout << grid[i] << endl;
    }
    return 0;
}
