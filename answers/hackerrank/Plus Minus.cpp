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
    vector<int> arr(n);
    double positive = 0;
    double negative = 0;
    double zeros = 0;
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
       positive += arr[arr_i] > 0;
       negative += arr[arr_i] < 0;
       zeros += arr[arr_i] == 0;
    }
    cout << positive / n << endl << negative / n << endl << zeros / n << endl;
    return 0;
}
