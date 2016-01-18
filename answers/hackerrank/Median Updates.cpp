//@result Submitted a few seconds ago • Score: 70.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0.02s Test Case #3: 0.02s Test Case #4: 0.02s Test Case #5: 0.02s Success Test Case #6: 0.24s Test Case #7: 0.24s Test Case #8: 0.24s Test Case #9: 0.26s

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
/* Head ends here */

void median(vector<char> s,vector<int> X) {
    multiset<int> less;
    multiset<int> greater;
    for (size_t i = 0; i < s.size(); ++ i) {
        bool find_flag = false;
        switch (s[i]) {
        case 'r':
            find_flag = false;
            if (less.size()) {
                if (X[i] <= * less.rbegin()) {
                    pair<multiset<int>::iterator, multiset<int>::iterator> range = less.equal_range(X[i]);
                    if (range.first != range.second) {
                        less.erase(range.first);
                        find_flag = true;
                    }
                }
                else {
                    pair<multiset<int>::iterator, multiset<int>::iterator> range = greater.equal_range(X[i]);
                    if (range.first != range.second) {
                        greater.erase(range.first);
                        find_flag = true;
                    }
                }
            }
            if (! find_flag) {
                cout << "Wrong!" << endl;
                continue;
            }
            break;
        case 'a':
            if (0 == less.size() || X[i] <= *less.rbegin()) {
                less.insert(X[i]);
            }
            else {
                greater.insert(X[i]);
            }
            break;
        default:
            break;
        }
        while (less.size() < greater.size()) {
            less.insert(*greater.begin());
            greater.erase(greater.begin());
        }
        while (less.size() > greater.size() + 1) {
            greater.insert(*prev(less.end()));
            less.erase(prev(less.end()));
        }
        if (0 == less.size() && 0 == greater.size()) {
            cout << "Wrong!" << endl;
        }
        else if (less.size() > greater.size()) {
            cout << *less.rbegin() << endl;
        }
        else {
            double dsum = (double(*less.rbegin()) + double(*greater.begin()));
            long long lsum = (long long) (*less.rbegin()) + (long long) (*greater.begin());
            if (dsum / 2 == lsum / 2) {
                cout << lsum / 2 << endl;
            }
            else {
                // avoid being printed as exponent
                cout << setprecision(1) << fixed << dsum / 2 << endl;
            }
        }
    }

}
int main(void){

//Helpers for input and output

   int N;
   cin >> N;

   vector<char> s;
    vector<int> X;
   char temp;
    int tempint;
   for(int i = 0; i < N; i++){
      cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
   }

   median(s,X);
   return 0;
}
