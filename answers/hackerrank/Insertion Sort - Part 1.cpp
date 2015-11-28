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
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
void insertionSort(vector <int>  ar) {
    bool flag = true;
    while (flag) {
        int temp = ar.back();
        flag = false;
        for (size_t i = ar.size() - 1; i < ar.size(); -- i) {
            if (i > 0 && ar[i - 1] > temp) {
                ar[i] = ar[i - 1];
                flag = true;
            }
            else {
                ar[i] = temp;
            }
            if (flag) {
                for (size_t j = 0; j < ar.size(); ++ j) {
                    cout << (j ? " " : "") << ar[j];
                }
                cout << endl;
            }
            if (0 == i || ar[i - 1] <= temp) {
                break;
            }
        }
    }

}
int main(void) {
   vector <int>  _ar;
   int _ar_size;
cin >> _ar_size;
for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
   int _ar_tmp;
   cin >> _ar_tmp;
   _ar.push_back(_ar_tmp);
}

insertionSort(_ar);

   return 0;
}
