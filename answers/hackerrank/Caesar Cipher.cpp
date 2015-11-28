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
    string s;
    cin >> s;
    int k;
    cin >> k;
    for (size_t i = 0; i < s.length(); ++ i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = (s[i] - 'a' + k) % 26 + 'a';
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = (s[i] - 'A' + k) % 26 + 'A';
        }
    }
    cout << s << endl;
    return 0;
}
